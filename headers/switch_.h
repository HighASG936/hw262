#ifndef switch_h
#define switch_h

#include "stdint.h"

typedef uint8_t SwitchPinNumber;

class switch_
{
    public:
        switch_();
    
        //Buttons pin number
        static const SwitchPinNumber s1 = 15;
        static const SwitchPinNumber s2 = 16;
        static const  SwitchPinNumber s3 = 17;

        bool IsPressed(SwitchPinNumber switch_pin);
    
    private:
        const SwitchPinNumber Switches[3]={s1, s2, s3};
};

#endif
