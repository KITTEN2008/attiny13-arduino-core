#ifndef CORE_BUILD_OPTIONS_H
#define CORE_BUILD_OPTIONS_H

#define F_CPU 9600000UL
#define F_CPU_INTERNAL 9600000UL
#define ARDUINO 10819
#define ATTINY13 1

// Конфигурация памяти
#define RAM_START 0x0060
#define RAM_END 0x009F
#define FLASH_START 0x0000
#define FLASH_END 0x03FF

// Настройки таймера для millis()
#define TIMER0_PRESCALER 64
#define TIMER0_TOP 249
#define TIMER0_OVERFLOW_COUNT 1000

#endif
