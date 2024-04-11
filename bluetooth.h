#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "Arduino.h"

class Bluetooth
{
    public:
        Bluetooth();
        static void send_temp(uint8_t temp);
        static void send_threshold(uint8_t threshold);
        static uint8_t get_received_threshold(); 
        

    private:
        static volatile uint8_t received_threshold;
        static const uint8_t startTx = 119;
        static const uint8_t isTemp = 32;
        static const uint8_t isThreshold = 33;
        static const uint8_t endTx = 170;
        static void send_data(uint8_t type, uint8_t value);
};

#endif
