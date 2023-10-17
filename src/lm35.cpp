
#include "../headers/lm35.h"

lm35::lm35(uint8_t precision)
{
  this->precision = precision;

  for(uint8_t i=0; i<this->precision; i++)
  {
    this->precision_factor *= 10;
  }

}

uint16_t lm35::read_lm35_sensor()
{
  return analogRead(SENSOR_TEMP_PIN);
}

uint16_t lm35::measure_centigrads()
{
    uint16_t real_temperature = (SOURCE_VOLTAGE/MAX_VALUE_ADC)*read_lm35_sensor() * LM35_SENSOR_GAIN;
    real_temperature *= this->precision_factor;
    return real_temperature;
}
