
#include <hw262.h> //Add HW262 library

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.display.clear(); // Clear display    
}


void loop()
{
    if(HW262.IsPressed(S1_PIN)) HW262.ledToggle(D1_PIN);
    if(HW262.IsPressed(S2_PIN)) HW262.ledToggle(D2_PIN);
    if(HW262.IsPressed(S3_PIN)) HW262.ledToggle(D3_PIN);
    delay(200);
}

