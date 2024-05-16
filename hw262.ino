
#include "hw262.h"

float temp;

void setup() {
  HW262.begin();
  HW262.display.clear();
}

void loop() {  
  temp = HW262.ds18.getTemp();  
  Serial.println(temp);
  for(uint32_t i=0; i<1000; i++) HW262.display.write( (float).015 );
}

