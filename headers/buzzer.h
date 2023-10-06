#ifndef buzzer_h
#define buzzer_h

#define BUZZER_PIN 3

class buzzer
{
    public:
        buzzer();
        static void buzzerOn();
        static void buzzerOff();
        static void buzzerToggle();
};

#endif
