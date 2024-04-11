#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class Buzzer
{
        public:
            Buzzer();
            static void buzzerOn();
            static void buzzerOff();
            static void buzzerToggle();
};

#endif
