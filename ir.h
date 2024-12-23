#ifndef IR_H
#define IR_H

#include <Arduino.h>
#include "pins.h"


#define IR_RECEIVE_PIN 2

typedef struct irdata_t {
  uint16_t address;
  uint16_t command;
  uint64_t raw_data;
} irdata_t;

/**
 * @class IR
 * @brief A class to handle IR (Infrared) communication.
 */
class IR {
public:
  /**
   * @brief Initializes the IR communication.
   *
   * @param feedback_led A boolean indicating whether to use a feedback LED.
   */
  static void begin(bool feedback_led);

  /**
   * @brief Retrieves the IR command.
   *
   * @param irdata A pointer to an irdata_t structure to store the received IR
   * data.
   * @return int32_t The command received via IR.
   */
  static int32_t getCommand(irdata_t *irdata);
};

#endif // IR_H
