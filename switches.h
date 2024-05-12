#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>
#include "pins.h"


class Switches
{
    public:
        Switches();
        static bool IsPressed(SwitchPinNumber switch_pin);
    
};

#endif

