#include "switches.h"

Switches::Switches()
{
    for(uint8_t i; i<sizeof(Switches); i++)
    {
        pinMode(switchesArray[i], INPUT);
    }
}

bool Switches::IsPressed(SwitchPinNumber switch_pin)
{
    return !digitalRead(switch_pin);
}
