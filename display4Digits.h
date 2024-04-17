#ifndef DISPLAY_4DIGITS_H
#define DISPLAY_4DIGITS_H

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class display4Digits
{    
    protected:
        static bool NUMBERS[14][7];
        static void Clk();
        static void Latch();
        static void sendBitToDotting(bool dot);
        static void sendShifterBits();
        static void displayDigit(bool position[]);

        static void writeUnits(uint16_t UserNumber);
        static void writeTens(uint16_t UserNumber);
        static void writeHundreds(uint16_t UserNumber);
        static void writeThousands(uint16_t UserNumber);
        static void writeDigit(uint16_t UserNumber, bool a=false, bool b=false, bool c=false, bool d=false, bool dot=false);
        static void sendBitsOfDigit(uint16_t NumberToWrite);

    public:
        display4Digits();        
        static void writeNumber(uint16_t NumberToWrite);
        static void clearDisplay();        
};

#endif

