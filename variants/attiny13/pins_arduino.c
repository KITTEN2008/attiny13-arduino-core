/*
  pins_arduino.c - Pin definitions for ATtiny13
*/

#include <avr/io.h>
#include "pins_arduino.h"

// Определение структуры пина для Arduino
struct __attribute__((packed)) PinDescription {
    uint8_t port;
    uint8_t bit;
    uint8_t timer;
    uint8_t adc;
};

// Таблица пинов
const struct PinDescription g_APinDescription[] = {
    // PB0 - Pin 0
    { PORTB, 0, 1, 0 },  // TIMER0A, ADC0
    // PB1 - Pin 1
    { PORTB, 1, 0, 1 },  // TIMER0B, ADC1
    // PB2 - Pin 2
    { PORTB, 2, 0, 2 },  // ADC2
    // PB3 - Pin 3
    { PORTB, 3, 0, 3 },  // ADC3
    // PB4 - Pin 4
    { PORTB, 4, 0, 0 },  // No ADC
    // PB5 - Pin 5
    { PORTB, 5, 0, 0 },  // No ADC
};

// Имена пинов для Arduino
const char* const PIN_NAMES[] = {
    "PB0",
    "PB1",
    "PB2",
    "PB3",
    "PB4",
    "PB5"
};

// Номера пинов по умолчанию
const uint8_t SS_PIN = 0;
const uint8_t MOSI_PIN = 1;
const uint8_t MISO_PIN = 2;
const uint8_t SCK_PIN = 3;

const uint8_t SDA_PIN = 0;
const uint8_t SCL_PIN = 1;

// Количество пинов
const uint8_t NUM_DIGITAL_PINS = 6;
const uint8_t NUM_ANALOG_INPUTS = 4;

// Функция для получения порта
uint8_t digitalPinToPort(uint8_t pin) {
    if (pin > 5) return 0;
    return g_APinDescription[pin].port;
}

// Функция для получения бита
uint8_t digitalPinToBit(uint8_t pin) {
    if (pin > 5) return 0;
    return g_APinDescription[pin].bit;
}

// Функция для получения таймера
uint8_t digitalPinToTimer(uint8_t pin) {
    if (pin > 5) return 0;
    return g_APinDescription[pin].timer;
}

// Функция для получения АЦП канала
uint8_t analogPinToChannel(uint8_t pin) {
    if (pin > 5) return 0;
    return g_APinDescription[pin].adc;
}

// Функция для получения указателя на порт
volatile uint8_t* portOutputRegister(uint8_t pin) {
    if (pin > 5) return 0;
    switch (g_APinDescription[pin].port) {
        case PORTB: return &PORTB;
        default: return 0;
    }
}

volatile uint8_t* portInputRegister(uint8_t pin) {
    if (pin > 5) return 0;
    switch (g_APinDescription[pin].port) {
        case PORTB: return &PINB;
        default: return 0;
    }
}

volatile uint8_t* portModeRegister(uint8_t pin) {
    if (pin > 5) return 0;
    switch (g_APinDescription[pin].port) {
        case PORTB: return &DDRB;
        default: return 0;
    }
}
