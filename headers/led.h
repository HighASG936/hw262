#ifndef led_h
#define led_h

#include "Arduino.h"
#include "stdint.h"

typedef uint8_t LedPinNumber;

class led
{       
    public:
        led();
        static void ledOn(LedPinNumber led_pin);
        static void ledOff(LedPinNumber led_pin);
        static void ledToggle(LedPinNumber led_pin);        

        //Leds Pin
        static const LedPinNumber d1 = 13;
        static const LedPinNumber d2 = 12;
        static const LedPinNumber d3 = 11;
        static const LedPinNumber d4 = 10;

    private:
        LedPinNumber Pinesled[4]={d1, d2, d3, d4};
};

#endif
