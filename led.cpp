#include "led.h"


Led::Led()
{
    for(uint8_t pinLed=D4_PIN; pinLed<=D1_PIN; pinLed++)
    {
        pinMode(pinLed, OUTPUT);
        ledOff(pinLed);
    }
}

  
void Led::ledOn(LedPinNumber pinLed)
{
    digitalWrite(pinLed, LOW);
}


void Led::ledOff(LedPinNumber pinLed)
{
    digitalWrite(pinLed, HIGH);
}


void Led::ledToggle(LedPinNumber pinLed)
{
    bool state = !digitalRead(pinLed);
    digitalWrite(pinLed, state);
}

