
#include "hw262.h"

float temp;

void setup() {
  HW262.begin();
  temp = HW262.ds18.getTemp();
  HW262.display.clear();
}

void loop() {  
  HW262.display.write( (float) temp );
}

