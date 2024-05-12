#ifndef DISPLAY_4DIGITS_H
#define DISPLAY_4DIGITS_H

#include <Arduino.h>
#include <mc74hc595a.h>
#include <math.h>
#include "constants.h"
#include "pins.h"


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

class Display
{    
    protected:
        static const byte* numbers[10];
        static byte convertCharToSegments(char c);
        static char* convertIntToBytes(int16_t number, bool left_zeros=false);
        static Mc74hc595a ic;     
        static const byte A, B, C, D, E, F, H, I, J, L, N, _N, O, P, R, S, T, U, Y;
        static const byte hyphen, minus, degrees, dot, Blank;

    public:
        static void write(const char* text);        
        static void write(int16_t number, bool left_zeros=false, uint8_t offset=0);
        static void write(float number);
        static void write(byte symbol, uint8_t position);
        static void writeInteger(int16_t number, bool left_zeros=false, uint8_t offset=0);
};

#endif

