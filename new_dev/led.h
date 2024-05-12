#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "pins.h"

class Led
{      
    public:
        Led();        
        static void ledOn(LedPinNumber led_pin);
        static void ledOff(LedPinNumber led_pin);
        static void ledToggle(LedPinNumber led_pin);        
};

#endif

