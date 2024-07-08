#include "switches.h"


Switches::Switches()
{
    for(uint8_t pin=S1_PIN; pin<S3_PIN; pin++) pinMode(pin, INPUT);
}


bool Switches::IsPressed(SwitchPinNumber switchPin)
{
    return !digitalRead(switchPin);
}
