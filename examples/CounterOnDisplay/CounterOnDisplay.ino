#include <hw262.h>

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
const uint64_t intervalTime = 1000;

void setup()
{
    HW262.begin();
    HW262.display.clear(); // Clear display
}

void loop()
{
    // Display counter to 0-9999
    currentTime = millis();
    while (elapsedTime < intervalTime)
    {
        elapsedTime = millis() - currentTime;
        HW262.display.writeNumber(number);
    }
    elapsedTime = 0;
    number++;
    if (number > 9999)
        number = 0;
}
