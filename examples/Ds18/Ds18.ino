#include <hw262.h>

float temp = 0;
uint64_t currentTime = 0;
uint64_t intervalTime = 0x800; // about 2 seconds


void setup() {
    Serial.begin(9600);
    HW262.begin();
    HW262.display.clear();
}


void loop() 
{
  temp = HW262.ds18.getTemp();  
  // for(uint32_t i=0; i<5000; i++) HW262.display.writeNumber(temp);
  while( ! temp );
  
  noInterrupts();
  while(currentTime < intervalTime)
  {
    HW262.display.writeNumber( (int16_t)temp*100 );
    HW262.display.writeDot(2);
    currentTime++;
  }
  currentTime = 0;
  interrupts();
  temp = 0;
}
