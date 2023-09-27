#ifndef pot_h
#define pot_h

#include "Arduino.h"

class pot
{       
    public:
        pot();
        int get_measure();  
        int get_voltage(); //measure and convert to voltage unit
    
    private:  
        int pot_Pin = A0;

};

#endif
