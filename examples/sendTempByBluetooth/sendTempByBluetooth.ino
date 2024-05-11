#include "hw262.h"

uint32_t wTime = 1500:

void setup() 
{
  HW262.begin();
  HW262.clearDisplay();
}

void loop()
{  
  String temp = String(HW262.ds18.getTemp())+"°C";
  Serial.println(temp);
  delay(wTime);
}

