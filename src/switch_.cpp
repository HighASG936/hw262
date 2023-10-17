#include "../headers/switch_.h"
#include "Arduino.h"

switch_::switch_()
{
    for(uint8_t i; i<sizeof(Switches); i++)
    {
        pinMode(Switches[i], INPUT);
    }
}

bool switch_::IsPressed(SwitchPinNumber switch_pin)
{
    return !digitalRead(switch_pin);
}
