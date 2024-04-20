#include "switches.h"

/**
 * @brief Construct a new Switches:: Switches object
 * 
 */
Switches::Switches()
{
    for(uint8_t i; i<sizeof(Switches); i++)
    {
        pinMode(switchesArray[i], INPUT);
    }
}


/**
 * @brief 
 * 
 * @param switch_pin 
 * @return true 
 * @return false 
 */
bool Switches::IsPressed(SwitchPinNumber switch_pin)
{
    return !digitalRead(switch_pin);
}
