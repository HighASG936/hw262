#ifndef lm35_h
#define lm35_h

#include "Arduino.h"
#include "constants.h"
#include "pins.h"

class lm35
{
    public:
        lm35(uint8_t precision);
        uint8_t precision;
        uint16_t precision_factor = 1;
        uint16_t read_lm35_sensor();
        uint16_t measure_centigrads();   
};

#endif
