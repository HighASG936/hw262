#include "buzzer.h"

/**
 * @brief Construct a new Buzzer:: Buzzer object
 * 
 */
Buzzer::Buzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
    buzzerOff();
}


/**
 * @brief 
 * 
 */
void Buzzer::buzzerOn()
{
    digitalWrite(BUZZER_PIN, LOW);    
}


/**
 * @brief 
 * 
 */
void Buzzer::buzzerOff()
{
    digitalWrite(BUZZER_PIN, HIGH);
}


/**
 * @brief 
 * 
 */
void Buzzer::buzzerToggle()
{
    digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
}
