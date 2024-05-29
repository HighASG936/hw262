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


  How create your own character:

  Examples:

    For '8.':
      bit:        0 0 0 0  0 0 0 0                    
      segment:    3 2 1 0  7 6 5 4

*/

// Letters
#define DISPLAY_A       0x11
#define DISPLAY_B       0xc1
#define DISPLAY_C       0x63
#define DISPLAY_D       0x85
#define DISPLAY_E       0x61 
#define DISPLAY_F       0x71
#define DISPLAY_G       0x09
#define DISPLAY_H       0x91
#define DISPLAY_I       0xf3
#define DISPLAY_J       0x87
#define DISPLAY_L       0xe3
#define DISPLAY_N       0xd5
#define DISPLAY__N      0x55
#define DISPLAY_O       0xc5
#define DISPLAY_P       0x31
#define DISPLAY_R       0xf5
#define DISPLAY_S       0x49
#define DISPLAY_T       0xe1
#define DISPLAY_U       0x83
#define DISPLAY_Y       0x89
#define DISPLAY_HYPHEN  0xfd
#define DISPLAY_MINUS   0xfd
#define DISPLAY_DEGRESS 0x39
#define DISPLAY_DOT     0xfe
#define DISPLAY_BLANK   0xff

// Numbers
#define DISPLAY_0       0x03
#define DISPLAY_1       0x9f
#define DISPLAY_2       0x25
#define DISPLAY_3       0x0d
#define DISPLAY_4       0x99
#define DISPLAY_5       0x49
#define DISPLAY_6       0x41
#define DISPLAY_7       0x1f
#define DISPLAY_8       0x01
#define DISPLAY_9       0x09

#define IS_NOT_VALID_NUMBER(number) (number < MIN_DISPLAY_NUMBER || number > MAX_DISPLAY_NUMBER)

class Display
{    
    protected:
        static const byte* numbers[10];
        static byte convertCharToSegments(char c);
        static char* convertIntToBytes(const int16_t number, bool left_zeros=false);
        static Mc74hc595a ic;     
        static const byte hyphen, minus, degrees, dot, Blank;
        static uint8_t getDotPosition(const float number);

    public:
        static void write(const char* text);        
        static void write(const int16_t number, bool left_zeros=false, uint8_t offset=0);
        static void write(const float number);
        static void write(byte symbol, uint8_t position);
        static void writeInteger(const int16_t number, bool left_zeros=false, uint8_t offset=0);
        static void clear();
};

#endif

