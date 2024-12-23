#include "ir.h"
#include <IRremote.hpp>

void IR::begin(bool feedback_led=false) {
  IrReceiver.begin(IR_RECEIVE_PIN, feedback_led);
  Serial.println("IR begin");
}

int32_t IR::getCommand(irdata_t *irdata) {
  if (!irdata) {
    return -1;
  }

  bool decoded = IrReceiver.decode();
  if (decoded) {
    IrReceiver.resume();
    irdata->address = IrReceiver.decodedIRData.address;
    irdata->command = IrReceiver.decodedIRData.command;
    irdata->raw_data = IrReceiver.decodedIRData.decodedRawData;
    return 0;
  }

  return -1;
}
