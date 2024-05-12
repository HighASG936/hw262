#include "switches.h"

/**
 * @brief Construct a new Switches:: Switches object
 * 
 */
Switches::Switches()
{
    for(uint8_t pin=S1_PIN; pin<S3_PIN; pin++) pinMode(pin, INPUT);
}


/**
 * @brief 
 * 
 * @param switch_pin 
 * @return true 
 * @return false 
 */
bool Switches::IsPressed(SwitchPinNumber switchPin)
{
    return !digitalRead(switchPin);
}
