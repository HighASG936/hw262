
#include <hw262.h> //Add HW262 library

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.display.clear();
}


void loop()
{
    HW262.buzzerOn();
    delay(10);
    HW262.buzzerOff();
    delay(2000);    
}

