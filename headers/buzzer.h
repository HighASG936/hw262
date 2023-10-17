#ifndef buzzer_h
#define buzzer_h

#include "stdint.h"
#include "constants.h"
#include "pins.h"

class buzzer
{
    public:
        buzzer();
        static void buzzerOn();
        static void buzzerOff();
        static void buzzerToggle();
};


#endif
