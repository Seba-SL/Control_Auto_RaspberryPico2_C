#ifndef APP_H
#define APP_H

#include "pico/stdlib.h"
#include "motors.h"

// Pines
#define ON 1
#define OFF 0

#define LED_PIN 25
#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13

// Array con los pines a controlar const 
uint8_t PORTS_OUT[] = {LED_PIN, IN1, IN2, IN3, IN4}; // Contamos la cantidad de elementos 

#define PORTS_OUT_CANT (sizeof(PORTS_OUT)/sizeof(PORTS_OUT[0]))




typedef enum {OK, ERROR} status_t;

// Prototipos
status_t app_setup(void);
status_t set_ports_out(void);
void set_uart(void);

status_t app_update(void);
void control_app(uint8_t desicion);

#endif
