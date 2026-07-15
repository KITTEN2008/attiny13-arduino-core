#include <avr/io.h>
#include <avr/interrupt.h>
#include "wiring_private.h"

void pinMode(uint8_t pin, uint8_t mode) {
    if (pin > 5) return;
    
    switch (mode) {
        case INPUT:
            DDRB &= ~(1 << pin);
            PORTB &= ~(1 << pin);
            break;
        case INPUT_PULLUP:
            DDRB &= ~(1 << pin);
            PORTB |= (1 << pin);
            break;
        case OUTPUT:
            DDRB |= (1 << pin);
            PORTB &= ~(1 << pin);
            break;
    }
}

void digitalWrite(uint8_t pin, uint8_t val) {
    if (pin > 5) return;
    
    if (val == HIGH) {
        PORTB |= (1 << pin);
    } else {
        PORTB &= ~(1 << pin);
    }
}

int digitalRead(uint8_t pin) {
    if (pin > 5) return 0;
    return (PINB & (1 << pin)) ? HIGH : LOW;
}
