#ifndef POT_HPP
#define POT_HPP

#include "constants.h"
#include "pins.h"
#include <Arduino.h>


class Pot {

public:
  /**
   * @brief Reads the potentiometer pin value
   *
   * @return int The analog value read from the potentiometer pin (0-1023)
   *         https://www.arduino.cc/reference/tr/language/functions/analog-io/analogread/
   */
  static int readPinPot() { return analogRead(POTENTIOMETER_PIN); }

  /**
   * @brief Get the Voltage object
   *
   * @return uint32_t Voltage value read from the potentiometer pin (0-5000)
   */
  static uint32_t getVoltagePot() {
    return (SOURCE_VOLTAGE * readPinPot()) / MAX_VALUE_ADC;
  }
};

#endif
