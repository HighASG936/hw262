#include "buzzer.h"

Buzzer::Buzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
    buzzerOff();
}

void Buzzer::buzzerOn()
{
    digitalWrite(BUZZER_PIN, LOW);    
}

void Buzzer::buzzerOff()
{
    digitalWrite(BUZZER_PIN, HIGH);
}

void Buzzer::buzzerToggle()
{
    digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
}
