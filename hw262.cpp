
#include "hw262.h"


Lm35 Hw262::tempSensor(DEFAULT_PRECISION);


void Hw262::begin(uint8_t sensorPrecision)
{
  this.sensorPrecision = sensorPrecision;
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

