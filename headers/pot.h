#ifndef pot_h
#define pot_h

#include "Arduino.h"

class pot
{       
    public:
        pot();
        uint16_t read_sensor();  
        uint16_t get_voltage();
    
    private:  
        uint8_t pot_Pin = A0;

};

#endif
