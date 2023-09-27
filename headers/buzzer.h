#ifndef buzzer_h
#define buzzer_h

class buzzer
{
    public:
        buzzer();
        void on();
        void off();
        void toggle();

    private:
        const char buzzer_pin = 3;
        bool state;
};

#endif
