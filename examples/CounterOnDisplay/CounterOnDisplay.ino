
#include <hw262.h> //Add HW262 library

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
uint64_t intervalTime = 1000;

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.clearDisplay(); // Clear display    
}


void loop()
{
    // Display counter to 0-9999
    currentTime = millis();
    while(elapsedTime<intervalTime)
    {   
        elapsedTime = millis()-currentTime;
        HW262.writeNumber(number);
    }
    elapsedTime = 0;
    number++;
    if(number > 9999) number = 0;
}

