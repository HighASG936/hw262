#include "../headers/switch_.h"
#include "Arduino.h"

switch_::switch_()
{
    for(int i; i<sizeof(Switches); i++)
    {
        pinMode(Switches[i], INPUT);
    }
}

bool switch_::IsPressed(SwitchPinNumber switch_pin)
{
    return !digitalRead(switch_pin);
}
