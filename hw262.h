#ifndef HW262_H
#define HW262_H

#include <Arduino.h>
#include "buzzer.h"
#include "led.h"
#include "pot.hpp"
#include "switches.h"
#include "display.h"
#include "ds18.h"
#include "lm35.h"
#include "ir.h"
#include "constants.h"
#include "pins.h"

class Hw262 :   public Led, 
                public Buzzer, 
                public Pot,
                public Switches
{
    protected:
        static uint16_t readA5();
        static uint16_t readVoltageA5();                       

    public:
        static void begin(uint8_t sensorPrecision=DEFAULT_PRECISION,uint32_t baudRate=SERIAL_BAUD_RATE);
        static Lm35 lm35;
        static Ds18 ds18;
        static Display display;
        static IR ir;
        static void resetAllLeds();
};

extern Hw262 HW262;

#endif

