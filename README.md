# Arduino Core for ATtiny13 / ATtiny13A / ATtiny13A-PU

Полноценное ядро Arduino для микроконтроллеров ATtiny13, ATtiny13A и ATtiny13A-PU.

## Особенности
- Поддержка внутреннего RC-генератора 9.6 МГц
- Все 6 GPIO (PB0-PB5)
- 4 канала АЦП (ADC0-ADC3)
- ШИМ на PB0 (OCR0A)
- Таймеры и прерывания
- Совместимость с Arduino IDE 1.8.x и 2.x

## Установка
1. Скачайте репозиторий
2. Поместите папку `attiny13-arduino-core` в `hardware/` вашей Arduino IDE
3. Перезапустите Arduino IDE
4. Выберите плату `ATtiny13` в меню Tools → Board

## Использование
```cpp
void setup() {
    pinMode(0, OUTPUT);
    digitalWrite(0, HIGH);
}

void loop() {
    // ваш код
}
