#include "Arduino.h"
#include "../headers/led.h"

led::led()
{
    for(int i; i<sizeof(Pinesled); i++)
    {
        pinMode(Pinesled[i], OUTPUT);
        off(Pinesled[i]);
    }
}

void led::on(LedPinNumber led_pin)
{
    digitalWrite(led_pin, LOW);
}

void led::off(LedPinNumber led_pin)
{
    digitalWrite(led_pin, HIGH);
}

void led::toggle(LedPinNumber led_pin)
{
    bool state = !digitalRead(led_pin);
    digitalWrite(led_pin, state);
}
