#ifndef lm35_h
#define lm35_h

#include "Arduino.h"

#define FACTOR_CONVERSION 0.2046

class lm35
{
    public:
        lm35();
        int read_sensor();
        int measure_centigrads();

    private:
        const char lm35_output = A4;
};

#endif