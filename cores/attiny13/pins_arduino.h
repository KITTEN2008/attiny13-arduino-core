#ifndef PINS_ARDUINO_H
#define PINS_ARDUINO_H

#include <avr/io.h>

#define NUM_DIGITAL_PINS 6
#define NUM_ANALOG_INPUTS 4

// Mapping пинов
#define PIN_A0 0
#define PIN_A1 1
#define PIN_A2 2
#define PIN_A3 3

#define PIN_D0 0
#define PIN_D1 1
#define PIN_D2 2
#define PIN_D3 3
#define PIN_D4 4
#define PIN_D5 5

// Прерывания по изменению пина
#define digitalPinToPCICR(p) ((p) < 4 ? (1 << PCIE0) : 0)
#define digitalPinToPCICRbit(p) ((p) < 4 ? PCIE0 : 0)
#define digitalPinToPCMSK(p) ((p) < 4 ? &PCMSK : 0)
#define digitalPinToPCMSKbit(p) ((p) < 4 ? (1 << (p)) : 0)

// SPI пины
static const uint8_t SS = 0;
static const uint8_t MOSI = 1;
static const uint8_t MISO = 2;
static const uint8_t SCK = 3;

// I2C пины (TWI)
static const uint8_t SDA = 0;
static const uint8_t SCL = 1;

// ШИМ пины
#define digitalPinToTimer(p) \
    ((p) == 0 ? &TCCR0A : NULL)
#define digitalPinToTimerBit(p) \
    ((p) == 0 ? (1 << COM0A1) : 0)

// Аналоговые пины
#define analogPinToChannel(p) ((p) < 4 ? (p) : 0)

#endif
