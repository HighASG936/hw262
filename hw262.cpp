
#include "hw262.h"

Ds18 Hw262::ds18;
Lm35 Hw262::lm35(DEFAULT_PRECISION);
Display Hw262::display;

void Hw262::begin(uint8_t sensorPrecision, uint32_t baudRate) {
  Serial.begin(baudRate);
  delay(100);
  Led();
  resetAllLeds();
  Buzzer();
  Switches();
  lm35.setPrecision(sensorPrecision);
  ds18.begin();
  ir.begin(false);
}

/**
 * @brief Read ADC channel at pin A5
 * @return uint16_t
 */
uint16_t Hw262::readA5() { return analogRead(A5); }

uint16_t Hw262::readVoltageA5() {
  return (SOURCE_VOLTAGE / MAX_VALUE_ADC) * readA5();
}

void Hw262::resetAllLeds() {
  for (uint8_t pinLed = D4_PIN; pinLed <= D1_PIN; pinLed++)
    ledOff(pinLed);
}
