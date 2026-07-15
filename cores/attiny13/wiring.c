#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "wiring_private.h"

volatile unsigned long timer0_millis = 0;
volatile unsigned long timer0_overflow_count = 0;

ISR(TIM0_OVF_vect) {
    timer0_overflow_count++;
    timer0_millis += 1;
}

void initVariant(void) __attribute__((weak));
void initVariant(void) {}

void init(void) {
    // Настройка тактирования
    CLKPR = (1 << CLKPCE);
    CLKPR = 0;
    #if F_CPU == 9600000UL
    // 9.6 МГц внутренний RC
    CLKPR = (1 << CLKPCE);
    CLKPR = 0;
    #elif F_CPU == 4800000UL
    CLKPR = (1 << CLKPCE);
    CLKPR = (1 << CLKPS0);
    #elif F_CPU == 1200000UL
    CLKPR = (1 << CLKPCE);
    CLKPR = (1 << CLKPS1) | (1 << CLKPS0);
    #endif

    // Сброс портов
    DDRB = 0;
    PORTB = 0;

    // Отключение аналоговых входов для экономии энергии
    DIDR0 = (1 << ADC0D) | (1 << ADC1D) | (1 << ADC2D) | (1 << ADC3D);

    // Настройка АЦП
    ADMUX = (1 << REFS0); // VCC как опорное
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Включить, предделитель 64

    // Настройка таймера 0 для millis()
    TCCR0A = 0;
    TCCR0B = (1 << CS01) | (1 << CS00); // Предделитель 64
    TIMSK0 = (1 << TOIE0); // Разрешить прерывание по переполнению
    TCNT0 = 0;

    // Отключение аналогового компаратора
    #if defined(ACSR)
    ACSR = (1 << ACD);
    #endif

    sei();

    initVariant();
}

int main(void) {
    init();
    setup();
    for (;;) {
        loop();
        if (serialEventRun) serialEventRun();
    }
    return 0;
}

void delay(unsigned long ms) {
    unsigned long start = millis();
    while (millis() - start < ms);
}

void delayMicroseconds(unsigned int us) {
    if (us == 0) return;
    us *= (F_CPU / 1000000UL) / 4;
    __asm__ __volatile__ (
        "1: sbiw %0,1" "\n\t"
        "brne 1b"
        : "=w" (us)
        : "0" (us)
    );
}

unsigned long millis(void) {
    unsigned long m;
    uint8_t oldSREG = SREG;
    cli();
    m = timer0_millis;
    SREG = oldSREG;
    return m;
}

unsigned long micros(void) {
    unsigned long m;
    uint8_t oldSREG = SREG;
    cli();
    m = timer0_overflow_count * 1000 + (TCNT0 * 1000) / 256;
    SREG = oldSREG;
    return m;
}
