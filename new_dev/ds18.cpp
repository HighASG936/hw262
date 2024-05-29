
#include "ds18.h"

OneWire Ds18::oneWireObjeto(DS18_SENSOR_PIN);
DallasTemperature Ds18::sensor(&oneWireObjeto);
DeviceAddress Ds18::addressDs18;

void Ds18::begin()
{
  int numberConnectedSensors;

  sensor.begin();
  numberConnectedSensors = sensor.getDeviceCount();
  if(numberConnectedSensors==1)
  {
      sensor.getAddress(addressDs18, 1);
  }
  else
  {
    Serial.println("Not found sensor");
  }  
}


float Ds18::getTemp()
{
  sensor.requestTemperatures();
  return sensor.getTempC(addressDs18);
}


bool Ds18::isConnected()
{
  return sensor.isConnected(addressDs18);
}


uint8_t* Ds18::getAddress()
{
  return addressDs18;
}
