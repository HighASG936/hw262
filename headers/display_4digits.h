#ifndef display_4digits_h
#define display_4digits_h

#include "Arduino.h"
#include "stdint.h"
#include "constants.h"
#include "pins.h"

class display_4digits
{
    public:
        display_4digits();        
        void Write_Number(uint16_t NumberToWrite);
        static void Clear_Display();
    
    private:

        const bool NUMBERS[14][7]={ 
                         {1,0,0,0,0,0,0}, //0 
                         {1,1,1,1,0,0,1}, //1
                         {0,1,0,0,1,0,0}, //2
                         {0,1,1,0,0,0,0}, //3 
                         {0,0,1,1,0,0,1}, //4
                         {0,0,1,0,0,1,0}, //5
                         {0,0,0,0,0,1,0}, //6
                         {1,1,1,1,0,0,0}, //7
                         {0,0,0,0,0,0,0}, //8
                         {0,0,1,1,0,0,0}, //9                         
                         {0,0,0,1,0,0,0}, //A
                         {0,0,0,0,0,1,1}, //b
                         {0,0,0,1,1,1,0}, //F
                         {1,0,0,0,0,0,0}  //O 
                         };

        static void Clk();
        static void Latch();
        static void Send_bit_to_dotting(bool dot);
        static void Send_Shifter_bits();
        static void Display_digit(bool position[]);

        void Write_Units(uint16_t UserNumber);
        void Write_Tens(uint16_t UserNumber);
        void Write_Hundreds(uint16_t UserNumber);
        void Write_Thousands(uint16_t UserNumber);
        void Write_Digit(uint16_t UserNumber, bool a, bool b, bool c, bool d, bool dot);
        void Send_bits_of_digit(uint16_t NumberToWrite);
};

#endif
