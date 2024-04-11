#ifndef HW262_H
#define HW262_H

#include <Arduino.h>
#include "buzzer.h"
#include "led.h"
#include "pot.hpp"
#include "switches.h"
#include "display4Digits.h"
#include "lm35.h"
#include "ds18.h"
#include "bluetooth.h"
#include "constants.h"

#define DEFAULT_PRECISION 1
#define LM35  lm35
#define DS18  ds18

class Hw262 :   public Led, 
                public Buzzer, 
                public Pot, 
                public display4Digits, 
                public Bluetooth,
                public Switches
{
    private:
        String currentTempSensor;

    protected:
        static uint16_t readA5();                       

    public:
        void begin(String currentTempSensor="");
        
        #if currentTempSensor == LM35
            static Lm35 tempSensor;
            #define SENSOR_MESSAGE "Selected temperature sensor: LM35"
        #endif

        #if currentTempSensor == DS18
            static Ds18 tempSensor;            
            #define SENSOR_MESSAGE "Selected temperature sensor: DS18"
        #else
            #define SENSOR_MESSAGE "ERROR: unsupported sensor. Select 'lm35' or 'ds18' only"
        #endif 

        static void resetAllLeds();
        static uint16_t readVoltageA5();
        
};

extern Hw262 HW262;

#endif

