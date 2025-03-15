#include <hw262.h>

char *TextArray[10] = {"pdq=", "beaf","a0b1","err4","4sea","b0b0","liq7","--20","-H0-","a=2"};

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
const uint64_t intervalTime = 200;

void setup() {
  HW262.begin();
  HW262.display.clear();  // Clear display
}

void loop() {
  // Display counter to 0-9999
  currentTime = millis();
  while (elapsedTime < intervalTime) {
    elapsedTime = millis() - currentTime;
    HW262.display.write(TextArray[number]);
  }
  elapsedTime = 0;
  if(++number>9) number = 0;
}
