#include "../headers/hw262.h"



hw262::hw262(tempSensorType currentTempSensor, uint8_t precision = 1) : tempSensor(precision)
{
    this->currentTempSensor = currentTempSensor;    
}

uint16_t hw262::readA5()
{
    return analogRead(A5);
}

uint16_t hw262::readVoltageA5()
{
    return  (SOURCE_VOLTAGE/MAX_VALUE_ADC)*readA5();
}
