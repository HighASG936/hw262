#include <hw262.h>

int temp;

void setup() {
    Serial.begin(9600);
    HW262.begin();
    HW262.display.clear();
}


void loop() 
{
  temp = HW262.ds18.getTemp();  
  // for(uint32_t i=0; i<5000; i++) HW262.display.writeNumber(temp);
}