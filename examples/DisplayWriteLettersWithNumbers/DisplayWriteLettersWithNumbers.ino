#include <hw262.h>

char *TextArray[10] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVXY", "0123", "4567", "890-", "=-_-" };

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
const uint64_t intervalTime = 150;

void setup() {
  HW262.begin();
  HW262.display.clear();  // Clear display
}

String TextLeftRotate(String text) {
  String temp = text;
  for (int i = 0; i < text.length() - 1; i++) {
    text[i] = text[i + 1];
  }
  text[text.length() - 1] = temp[0];
  return text;
}

String TextRightRotate(String text) {
  String temp = text;
  for (int i = text.length() - 1; i > 0; i--) {
    text[i] = text[i - 1];
  }
  text[0] = temp[temp.length() - 1];
  return text;
}

String abc = "   STRING ROTATION LEFT 2025   ";

void loop() {
  abc = TextLeftRotate(abc);
  
  currentTime = millis();
  while (elapsedTime < intervalTime) {
    elapsedTime = millis() - currentTime;
    String dtxt = abc.substring(0, 4);
    HW262.display.write(dtxt.c_str());
  }
  elapsedTime = 0;
  if(++number>9) number = 0;
}
