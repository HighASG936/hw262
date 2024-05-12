#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>
#include "pins.h"


class Switches
{
    protected:
        const SwitchPinNumber switchesArray[3]={s1, s2, s3};

    public:
        Switches();
        static bool IsPressed(SwitchPinNumber switch_pin);
    
};

#endif

