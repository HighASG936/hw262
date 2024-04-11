#ifndef POT_HPP
#define POT_HPP

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class Pot
{       
    static uint8_t read_pot_sensor()
    {
        return analogRead(POTENCIOMETER_PIN);
    }

    static uint8_t get_voltage()
    {
        return (SOURCE_VOLTAGE/MAX_VALUE_ADC)*read_pot_sensor();
    }
};

#endif
