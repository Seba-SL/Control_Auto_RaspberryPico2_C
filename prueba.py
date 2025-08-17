from machine import Pin, PWM
from time import sleep

# Pines motores
ENA = PWM(Pin(0))   # Enable Motor A
IN1 = Pin(2, Pin.OUT)
IN2 = Pin(3, Pin.OUT)

ENB = PWM(Pin(1))   # Enable Motor B
IN3 = Pin(4, Pin.OUT)
IN4 = Pin(5, Pin.OUT)

# Configuración PWM
ENA.freq(1000)
ENB.freq(1000)

def motorA(forward, speed=65025):
    ENA.duty_u16(speed)
    if forward:
        IN1.value(1)
        IN2.value(0)
    else:
        IN1.value(0)
        IN2.value(1)

def motorB(forward, speed=65025):
    ENB.duty_u16(speed)
    if forward:
        IN3.value(1)
        IN4.value(0)
    else:
        IN3.value(0)
        IN4.value(1)

def stop():
    ENA.duty_u16(0)
    ENB.duty_u16(0)

# Ejemplo de movimientos
print("Avanzar")
motorA(True, 40000)
motorB(True, 40000)
sleep(2)

print("Retroceder")
motorA(False, 40000)
motorB(False, 40000)
sleep(2)

print("Girar izquierda")
motorA(False, 40000)
motorB(True, 40000)
sleep(2)

print("Girar derecha")
motorA(True, 40000)
motorB(False, 40000)
sleep(2)

print("Parar")
stop()
