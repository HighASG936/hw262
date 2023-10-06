#ifndef lm35_h
#define lm35_h

#include "Arduino.h"



class lm35
{
    public:
        lm35();
        static uint16_t read_sensor();
        static uint16_t measure_centigrads();

    private:
        static const uint8_t lm35_output = A4;
        static const float Factor_conversion = 0.2046;
};

#endif