#include "../headers/buzzer.h"
#include "Arduino.h"

buzzer::buzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
    buzzerOff();
}

void buzzer::buzzerOn()
{
    digitalWrite(BUZZER_PIN, LOW);    
}

void buzzer::buzzerOff()
{
    digitalWrite(BUZZER_PIN, HIGH);
}

void buzzer::buzzerToggle()
{
    digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
}
