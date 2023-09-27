#ifndef switch_h
#define switch_h


class switch_
{
    typedef char SwitchPinNumber;
    
    public:
        switch_();
        bool IsPressed(SwitchPinNumber switch_pin);
        
        SwitchPinNumber s1 = 15;
        SwitchPinNumber s2 = 16;
        SwitchPinNumber s3 = 17;
        SwitchPinNumber Switches[3]={s1, s2, s3};
};

#endif
