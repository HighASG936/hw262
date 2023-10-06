#ifndef hw262_h
#define hw262_h

#include "Arduino.h"
#include "buzzer.h"
#include "led.h"
#include "pot.h"
#include "switch_.h"
#include "display_4digits.h"
#include "lm35.h"
#include "stdint.h"

class hw262 : public led, public buzzer, public pot, public lm35, public display_4digits, public switch_
{    
    private: 
        const uint8_t pinA5 = A5;
};

#endif
