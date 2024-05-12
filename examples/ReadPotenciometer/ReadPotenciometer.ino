

#include <hw262.h> //Add HW262 library

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.clearDisplay(); // Clear display    
}


void loop()
{
    uint8_t v = HW262.getVoltagePot();
    Serial.println(String(v)+" mV");
    delay(1000);
}

