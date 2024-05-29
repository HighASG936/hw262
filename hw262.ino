
#include "hw262.h"

int16_t j=0;
float temp;

void setup() {
  HW262.begin();
  HW262.display.clear();
}

void loop() {  
  //temp = HW262.ds18.getTemp();  
  Serial.println(j);
  for(uint32_t i=0; i<100; i++) HW262.display.write(j);
  HW262.display.clear();
  if(j>1000) j=0;
  j++;
}

