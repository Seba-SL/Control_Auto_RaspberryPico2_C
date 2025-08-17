#include "pico/stdlib.h"
#include "app.h"
#include "hardware/uart.h"


motor_t motor_atras = {IN1, IN2, STOP};

motor_t motor_delantero = {IN3, IN4 , STOP};

int main() 
{
    if(app_setup()!= OK)
    {
        return ERROR;
    }   
    

    if(app_update() != OK)
    {
        return ERROR;
    }
}



status_t app_setup()
{   
    set_uart();

    set_ports_out();

    
    return OK;

}



status_t app_update()
{   
   

    motor_atras.st = HORARIO;
    motor_delantero.st = HORARIO;

    while (true)
    {

        
        sleep_ms(100);
        //MotorToggle(&motor_atras);
        //MotorToggle(&motor_delantero);

        sleep_ms(500);
       
    }

    return OK;

}

status_t set_ports_out()
{

    for(int i= 0 ; i < PORTS_OUT_CANT ; i++ )
    {
        gpio_init(PORTS_OUT[i]);
        gpio_set_dir(PORTS_OUT[i], GPIO_OUT);

    }

    return OK;
}


 void set_uart()
 {
    uart_init(uart1, 115200); // Inicializa UART1 a 115200 baudios
    gpio_set_function(4, GPIO_FUNC_UART); // Asigna GPI4 como TX de UART1
    gpio_set_function(5, GPIO_FUNC_UART); // Asigna GPI5 como RX de UART1

 }

void MotorHorario(motor_t * m )
{

    gpio_put(m->b1, ON);

    gpio_put(m->b2 , OFF);

    m->st = HORARIO;

}

//función para girar el motor en sentido antihorario

void MotorAntihorario(motor_t * m )
{

    gpio_put(m->b1, OFF);

    gpio_put(m->b2, ON);
    
    m->st = ANTIHORARIO;

}


 

//función para apagar el motor

void MotorStop(motor_t *m)
{

     gpio_put(m->b1, OFF);

     gpio_put(m->b2, OFF);

     m->st = STOP;
}



void MotorToggle(motor_t *m)
{

   
    switch(m->st)
    {
        case HORARIO:
            MotorAntihorario(m);
            break;
        case ANTIHORARIO:
            MotorHorario(m);
            break;
        case STOP:
        default:
            MotorStop(m);
            break;
    }
}