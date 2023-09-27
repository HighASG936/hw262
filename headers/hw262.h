#ifndef hw262_h
#define hw262_h

#include "buzzer.h"
#include "led.h"
#include "pot.h"
#include "switch_.h"
#include "display_4digits.h"
#include "lm35.h"


typedef char LedPinNumber;
typedef char SwitchPinNumber;
typedef String TemperatureSensor;
typedef String TempUnits;


class hw262
{    
    public:      
        hw262();

        led Led;
        buzzer Buzzer;
        pot Pot;
        switch_ Switch;
        display_4digits Display;
        lm35 TempSensor;

    private: 
        const char a5_pin = 19;
};

#endif
