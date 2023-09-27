#include "../headers/buzzer.h"
#include "Arduino.h"

buzzer::buzzer()
{
    pinMode(buzzer_pin, OUTPUT);
    off();
}

void buzzer::on()
{
    state = LOW;
    digitalWrite(buzzer_pin, state);    
}

void buzzer::off()
{
    digitalWrite(buzzer_pin, HIGH);
}

void buzzer::toggle()
{
    state = !state;
    digitalWrite(buzzer_pin, state);
}
