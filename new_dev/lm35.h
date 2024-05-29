#ifndef LM35_H
#define LM35_H

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class Lm35
{
    protected:
        static uint8_t precision;
        static uint16_t precisionFactor;        

    public:
        Lm35(uint8_t precision);            
        static uint16_t readLm35Sensor();
        static uint16_t measureCentigrads();
        static void setPrecision(uint8_t newValue);
};

#endif

