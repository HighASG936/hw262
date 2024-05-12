
#include "hw262.h"

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
uint64_t intervalTime = 100;

void setup()
{
    HW262.begin();
    HW262.clearDisplay();
}


void loop()
{
    currentTime = millis();
    uint32_t voltage = HW262.getVoltagePot();

    while(elapsedTime<intervalTime)
    {   
        elapsedTime = millis()-currentTime;
        HW262.writeNumber(voltage);
    }
    elapsedTime = 0;
}

