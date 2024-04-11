
#include "lm35.h"

uint16_t Lm35::precisionFactor = 1;


/**
 * @brief Construct a new Lm35::Lm35 object
 * 
 * @param precision 
 */
Lm35::Lm35(uint8_t precision)
{
  setPrecision(precision);

  for(uint8_t i=0; i<this->precision; i++)
  {
    this->precisionFactor *= 10;
  }

}

/**
 * @brief 
 * 
 * @return uint16_t 
 */
uint16_t Lm35::readLm35Sensor()
{
  return analogRead(SENSOR_TEMP_PIN);
}


/**
 * @brief 
 * 
 * @return uint16_t 
 */
uint16_t Lm35::measureCentigrads()
{
    uint16_t real_temperature = (SOURCE_VOLTAGE/MAX_VALUE_ADC)*readLm35Sensor() * LM35_SENSOR_GAIN;
    real_temperature *= precisionFactor;
    return real_temperature;
}


/**
 * @brief 
 * 
 * @param newValue 
 */
void Lm35::setPrecision(uint8_t newValue)
{
  precision = newValue;
}
