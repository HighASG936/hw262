#ifndef display_4digits_h
#define display_4digits_h

#define DOT 1
#define NO_DOT 0
#define NUMBER_DIGITS 4
#define NUMBER_OUTPUTS_BOTH_MC74HC595A 16

class display_4digits
{
    public:
        display_4digits();        
        void Write_Number(int UserNumber);
        void Clear_Display();
    
    private:
        const char lchclk = 4;
        const char sftclk = 7;
        const char sdi = 8;

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
        void Clk();
        void Latch();
        void Send_bits_of_digit(int UserNumber);
        void Send_bit_to_dotting(bool dot);
        void Send_Shifter_bits();
        void Display_digit(bool position[]);
        void Write_Units(int UserNumber);
        void Write_Tens(int UserNumber);
        void Write_Hundreds(int UserNumber);
        void Write_Thousands(int UserNumber);
        void Write_Digit(int UserNumber, bool a, bool b, bool c, bool d, bool dot);
};

#endif
