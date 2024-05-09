
#include "hw262.h"

Ds18 Hw262::ds18;

Lm35 Hw262::lm35(DEFAULT_PRECISION);

/**
 * @brief 
 * 
 * @param sensorPrecision 
 */
void Hw262::begin(uint8_t sensorPrecision)
{
  Led();
  Buzzer();
  display4Digits();
  Switches();
  lm35.setPrecision(sensorPrecision);
  ds18.begin();
}


/**
 * @brief 
 * 
 * @return uint16_t 
 */
uint16_t Hw262::readA5()
{
    return analogRead(A5);
}


/**
 * @brief 
 * 
 * @return uint16_t 
 */
uint16_t Hw262::readVoltageA5()
{
    return(SOURCE_VOLTAGE/MAX_VALUE_ADC)*readA5();
}


/**
 * @brief 
 * 
 */
void Hw262::resetAllLeds()
{
  for(uint8_t i=0; i<sizeof(Pinesled);i++) ledOff(Pinesled[i]);
}

