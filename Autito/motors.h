#ifndef MOTORS_H
#define MOTORS_H

#include "pico/stdlib.h"
#include "app.h"

// Estado del motor
typedef enum {STOP, HORARIO, ANTIHORARIO} motor_state_t;

// Estructura del motor
typedef struct {
    uint8_t b1;
    uint8_t b2;
    motor_state_t st;
} motor_t;

// Prototipos de funciones
void MotorHorario(motor_t * m);
void MotorAntihorario(motor_t * m);
void MotorStop(motor_t *m);
void MotorToggle(motor_t *m);

#endif