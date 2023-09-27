#ifndef led_h
#define led_h


class led
{
    typedef char LedPinNumber;
    
    public:
        led();
        void on(LedPinNumber led_pin);
        void off(LedPinNumber led_pin);
        void toggle(LedPinNumber led_pin);

        

        LedPinNumber d1 = 13;
        LedPinNumber d2 = 12;
        LedPinNumber d3 = 11;
        LedPinNumber d4 = 10;

    private:
        LedPinNumber Pinesled[4]={d1, d2, d3, d4};
};

#endif
