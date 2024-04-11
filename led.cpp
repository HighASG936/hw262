#include "led.h"

LedPinNumber Led::Pinesled[4]={d1, d2, d3, d4};

Led::Led()
{
    for(uint8_t i=0; i<sizeof(Pinesled); i++)
    {
        pinMode(Pinesled[i], OUTPUT);
        ledOff(Pinesled[i]);
    }
}

void Led::ledOn(LedPinNumber led_pin)
{
    digitalWrite(led_pin, LOW);
}

void Led::ledOff(LedPinNumber led_pin)
{
    digitalWrite(led_pin, HIGH);
}

void Led::ledToggle(LedPinNumber led_pin)
{
    bool state = !digitalRead(led_pin);
    digitalWrite(led_pin, state);
}

