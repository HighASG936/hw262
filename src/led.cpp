#include "../headers/led.h"

led::led()
{
    for(uint8_t i=0; i<sizeof(Pinesled); i++)
    {
        pinMode(Pinesled[i], OUTPUT);
        ledOff(Pinesled[i]);
    }
}

void led::ledOn(LedPinNumber led_pin)
{
    digitalWrite(led_pin, LOW);
}

void led::ledOff(LedPinNumber led_pin)
{
    digitalWrite(led_pin, HIGH);
}

void led::ledToggle(LedPinNumber led_pin)
{
    bool state = !digitalRead(led_pin);
    digitalWrite(led_pin, state);
}
