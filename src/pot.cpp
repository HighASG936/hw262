#include "../headers/pot.h"

uint8_t pot::read_pot_sensor()
{
    return analogRead(POTENCIOMETER_PIN);
}

uint8_t pot::get_voltage()
{
    return (SOURCE_VOLTAGE/MAX_VALUE_ADC)*read_pot_sensor();
}
