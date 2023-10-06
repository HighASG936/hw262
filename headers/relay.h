#ifndef relay_h
#define relay_h

#include "Arduino.h"

class relay
{
    public:
        relay();
        static void relayOn();
        static void relayOff();
    
    private:
        static const uint8_t relayPin = 13;

};



#endif