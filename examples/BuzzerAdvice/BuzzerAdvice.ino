
#include <hw262.h> //Add HW262 library

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.clearDisplay(); // Clear display    
}


void loop()
{
    HW262.buzzerToggle();
    delay(300);
}

