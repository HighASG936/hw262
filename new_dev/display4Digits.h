#ifndef DISPLAY_4DIGITS_H
#define DISPLAY_4DIGITS_H

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class display4Digits
{    
/*

  7-segment display:
  Followed draw describe the position of each segment into every array

           __________
          |____7_____|
         _             _
        | |           | |
       2| |           | |6
        |_|           |_|                           
            __________
           |____1_____|
         _             _
        | |           | |
       3| |           | |5
        |_|           |_|     
            __________     _
           |_____4____|   |_| 0                           

*/
    protected:
        static bool Numbers[22][7];
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

