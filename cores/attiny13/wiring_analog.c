#include <avr/io.h>
#include <avr/interrupt.h>
#include "wiring_private.h"

uint8_t analog_reference = DEFAULT;

void analogReference(uint8_t mode) {
    analog_reference = mode;
    // REFS0 бит в ADMUX
    ADMUX = (ADMUX & ~(1 << REFS0)) | (mode & 1);
}

int analogRead(uint8_t pin) {
    uint8_t low, high;
    
    // Проверка допустимости пина
    if (pin >= 4) return 0;
    
    // Выбор канала
    ADMUX = (ADMUX & ~(1 << MUX0) & ~(1 << MUX1)) | (pin & 3);
    
    // Запуск преобразования
    ADCSRA |= (1 << ADSC);
    
    // Ожидание завершения
    while (ADCSRA & (1 << ADSC));
    
    // Чтение результата
    low = ADCL;
    high = ADCH;
    
    return (high << 8) | low;
}
