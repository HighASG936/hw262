#include "led.h"


/**
 * @brief Construct a new Led:: Led object
 * 
 */
Led::Led()
{
    for(uint8_t pinLed=d4; pinLed<=d1; pinLed++)
    {
        pinMode(pinLed, OUTPUT);
        ledOff(pinLed);
    }
}

  
/**
 * @brief 
 * 
 * @param led_pin 
 */
void Led::ledOn(LedPinNumber pinLed)
{
    digitalWrite(pinLed, LOW);
}


/**
 * @brief 
 * 
 * @param pinLed 
 */
void Led::ledOff(LedPinNumber pinLed)
{
    digitalWrite(pinLed, HIGH);
}


/**
 * @brief 
 * 
 * @param pinLed 
 */
void Led::ledToggle(LedPinNumber pinLed)
{
    bool state = !digitalRead(pinLed);
    digitalWrite(pinLed, state);
}

