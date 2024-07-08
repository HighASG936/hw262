
#include "lm35.h"

uint16_t Lm35::precisionFactor = 1;
uint8_t Lm35::precision;


Lm35::Lm35(uint8_t precision)
{
  setPrecision(precision);

  for(uint8_t i=0; i<this->precision; i++)
  {
    this->precisionFactor *= 10;
  }

}


uint16_t Lm35::readLm35Sensor()
{
  return analogRead(SENSOR_TEMP_PIN);
}


uint16_t Lm35::measureCentigrads()
{
    uint16_t real_temperature = (SOURCE_VOLTAGE/MAX_VALUE_ADC)*readLm35Sensor() * LM35_SENSOR_GAIN;
    real_temperature *= precisionFactor;
    return real_temperature;
}


void Lm35::setPrecision(uint8_t newValue)
{
  precision = newValue;
}
