#ifndef DISPLAY_4DIGITS_H
#define DISPLAY_4DIGITS_H

#include <Arduino.h>
#include "constants.h"
#include "pins.h"

class display4Digits
{    

    private:
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
bool display4Digits::Numbers[22]={ 
    new [7]{1,0,0,0,0,0,0}, //0 
    new [7]{1,1,1,1,0,0,1}, //1
    new [7]{0,1,0,0,1,0,0}, //2
    new [7]{0,1,1,0,0,0,0}, //3 
    new [7]{0,0,1,1,0,0,1}, //4
    new [7]{0,0,1,0,0,1,0}, //5
    new [7]{0,0,0,0,0,1,0}, //6
    new [7]{1,1,1,1,0,0,0}, //7
    new [7]{0,0,0,0,0,0,0}, //8
    new [7]{0,0,1,1,0,0,0}, //9
    new [7]{0,0,0,1,0,0,0}, //A
    new [7]{0,0,0,0,0,1,1}, //b
    new [7]{1,0,0,0,1,1,0}, //C
    new [7]{0,1,0,0,0,0,1}, //d
    new [7]{0,0,0,0,1,1,0}, //E
    new [7]{0,0,0,1,1,1,0}, //F
    new [7]{0,0,1,0,0,0,0}, //g
    new [7]{1,1,1,0,1,1,0}, //H
    new [7]{1,1,1,1,0,0,1}, //I
    new [7]{1,1,1,1,0,0,1}, //J
    new [7]{1,0,0,0,1,1,1}, //L
    new [7]{0,1,0,0,0,1,1}  //o
    // TODO: Finish with this
    };

    protected:

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

