
#ifndef DS18_H
#define DS18_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "pins.h"

class Ds18
{
  protected:
    static OneWire oneWireObjeto;
    static DeviceAddress addressDs18;
    static DallasTemperature sensor;
    
    static uint8_t* getAddress();

  public:
    static void begin();
    static float getTemp(); 
    static bool isConnected();      
    
};
#endif