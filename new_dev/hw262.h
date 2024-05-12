#ifndef HW262_H
#define HW262_H

#include <Arduino.h>
#include "buzzer.h"
#include "led.h"
#include "pot.hpp"
#include "switches.h"
#include "display4Digits.h"
#include "ds18.h"
#include "lm35.h"
#include "constants.h"


#define DEFAULT_PRECISION 1
#define SERIAL_BAUD_RATE 9600

class Hw262 :   public Led, 
                public Buzzer, 
                public Pot, 
                public display4Digits,
                public Switches
{
    protected:
        static uint16_t readA5();
        static uint16_t readVoltageA5();                       

    public:
        static void begin(uint8_t sensorPrecision=DEFAULT_PRECISION,uint32_t baudRate=SERIAL_BAUD_RATE);
        static Lm35 lm35;
        static Ds18 ds18;
        static void resetAllLeds();
};

extern Hw262 HW262;

#endif

