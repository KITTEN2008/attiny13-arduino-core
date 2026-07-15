#include <avr/io.h>
#include <avr/interrupt.h>
#include "wiring_private.h"

uint32_t pulseIn(uint8_t pin, uint8_t state, uint32_t timeout) {
    uint32_t start, end;
    uint8_t bit = pin;
    uint8_t mask = (1 << bit);
    uint32_t maxloops = microsecondsToClockCycles(timeout) / 16;
    
    if (pin > 5) return 0;
    
    // Ждем начало импульса
    while ((PINB & mask) != (state ? mask : 0)) {
        if (--maxloops == 0) return 0;
    }
    
    start = micros();
    
    // Ждем конец импульса
    while ((PINB & mask) == (state ? mask : 0)) {
        if (--maxloops == 0) return 0;
    }
    end = micros();
    
    return end - start;
}
