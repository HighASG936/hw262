#include <hw262.h>

void setup() {
  HW262.begin();
  HW262.display.clear();
}

void loop() {
  uint32_t v = HW262.getVoltagePot();
  Serial.println(String(v) + " mV");
  delay(1000);
}
