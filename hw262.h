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
#define LM35_SENSOR  lm35

class Hw262 :   public Led, 
                public Buzzer, 
                public Pot, 
                public display4Digits, 
                public Bluetooth,
                public Switches
{
    private: 
        String nameCurrentTempSensor;

    protected:
        static uint16_t readA5();
        static uint16_t readVoltageA5();                       

    public:
        Hw262(String nameCurrentTempSensor="");        
        static Lm35 tempSensor;
        static void resetAllLeds();
};

#endif

