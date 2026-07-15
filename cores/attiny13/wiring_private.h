#ifndef WIRING_PRIVATE_H
#define WIRING_PRIVATE_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Константы
#define HIGH 0x1
#define LOW 0x0
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define DEFAULT 1
#define EXTERNAL 0
#define INTERNAL 1
#define LSBFIRST 0
#define MSBFIRST 1
#define CHANGE 1
#define FALLING 2
#define RISING 3

// Функции
void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long millis(void);
unsigned long micros(void);
void init(void);
void initVariant(void);
void setup(void);
void loop(void);

// Pulse
uint32_t pulseIn(uint8_t pin, uint8_t state, uint32_t timeout);

// Shift
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

// Serial event
void serialEventRun(void) __attribute__((weak));

#ifdef __cplusplus
}
#endif

#endif
