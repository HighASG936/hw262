#ifndef pot_h
#define pot_h

#include "Arduino.h"
#include "constants.h"
#include "pins.h"

class pot
{       
    public:
        uint8_t read_pot_sensor();  
        uint8_t get_voltage();

};

#endif
