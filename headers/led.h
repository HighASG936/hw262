#ifndef led_h
#define led_h

#include "Arduino.h"
#include "stdint.h"
#include "pins.h"

class led
{       
    public:
        led();
        static void ledOn(LedPinNumber led_pin);
        static void ledOff(LedPinNumber led_pin);
        static void ledToggle(LedPinNumber led_pin);

        LedPinNumber Pinesled[4]={d1, d2, d3, d4};
};

#endif
