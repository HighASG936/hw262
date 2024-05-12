
#include "hw262.h"

float temp;

void setup() {
  HW262.begin();
}

void loop() {
  temp = HW262.ds18.getTemp();
  Serial.println(temp);
  HW262.display.write( (float) temp );
  delay(1000);
}

