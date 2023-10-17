#ifndef hw262_h
#define hw262_h

#include "Arduino.h"
#include "buzzer.h"
#include "led.h"
#include "pot.h"
#include "switch_.h"
#include "display_4digits.h"
#include "lm35.h"
#include "ds18.h"
#include "stdint.h"
#include "constants.h"

typedef String tempSensorType;

class hw262 :   public led, public buzzer, 
                public pot, public display_4digits, 
                public switch_
{

    private:
        tempSensorType LM35 = "lm35";
        tempSensorType DS18 = "ds18";
        tempSensorType currentTempSensor;

    public:
        hw262(tempSensorType currentTempSensor, uint8_t precision);        

        #if currentTempSensor == LM35
            lm35 tempSensor;
            #define SENSOR_MESSAGE "Selected temperature sensor: LM35"
        #elif currentTempSensor == DS18
            ds18 tempSensor;            
            #define SENSOR_MESSAGE "Selected temperature sensor: DS18"
        #else
            #define SENSOR_MESSAGE "ERROR: unsupported sensor. Select 'lm35' or 'ds18' only"
        #endif                

        
        static uint16_t readA5();
        static uint16_t readVoltageA5();
        
};

#endif
