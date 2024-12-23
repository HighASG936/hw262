#include <hw262.h>

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
uint64_t intervalTime = 100;
irdata_t data;

void setup() {
  HW262.begin();
  HW262.display.clear();
  memset(&data, 0x00, sizeof(data));
}

void loop() {
  currentTime = millis();

  int error = HW262.ir.getCommand(&data);

  if (!error)
    Serial.println((long unsigned int)data.raw_data);

  while (elapsedTime < intervalTime) {
    elapsedTime = millis() - currentTime;
    HW262.display.writeNumber(data.command);
  }

  elapsedTime = 0;
}
