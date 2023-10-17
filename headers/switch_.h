#ifndef switch_h
#define switch_h

#include "stdint.h"
#include "pins.h"


class switch_
{
    public:
        switch_();
        bool IsPressed(SwitchPinNumber switch_pin);
    
    private:
        const SwitchPinNumber Switches[3]={s1, s2, s3};
};

#endif
