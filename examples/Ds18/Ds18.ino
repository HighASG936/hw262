#include "hw262.h"

int temp;

void setup() {
    Serial.begin(9600);
    HW262.begin();
}


void loop() 
{
  temp = HW262.ds18.getTemp();
  HW262.clearDisplay();
  for(uint32_t i=0; i<5000; i++) HW262.writeNumber(temp);
}

