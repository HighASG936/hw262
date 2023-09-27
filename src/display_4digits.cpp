#include "../headers/display_4digits.h"
#include "Arduino.h"


display_4digits::display_4digits()
{
  pinMode(sftclk, OUTPUT);
  pinMode(lchclk, OUTPUT);
  pinMode(sdi, OUTPUT);
}

/***************************************************************
@Name:   Clk
@Brief:  Pulse of Clock      
@Params: N/A
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Clk()
{
  digitalWrite(sftclk,LOW);
  digitalWrite(sftclk,HIGH);
}

/***************************************************************
@Name:   Latch
@Brief:  Pulse of Latch      
@Params: N/A
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Latch()
{
  digitalWrite(lchclk,LOW);
  digitalWrite(lchclk,HIGH);
}

/***************************************************************
@Name:   Clear_Display
@Brief:  Erease all numbers on display      
@Params: N/A
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Clear_Display()
{ 
  for(int i=0;i<NUMBER_OUTPUTS_BOTH_MC74HC595A;i++)
  {
    digitalWrite(sdi,HIGH);
    Clk();
  }       
  Latch();
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Send_bit_to_dotting(bool dot)
{
  digitalWrite(sdi,!dot);
  Clk();
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Send_bits_of_digit(int UserNumber)
{
  for(int i=0;i<7;i++)
  {
    digitalWrite(sdi,NUMBERS[UserNumber][i]);
    Clk();
  }
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Send_Shifter_bits()
{
  //Shift from QE to QH bits (see schematic)
  for(int i=0;i<4;i++)
  {
    digitalWrite(sdi,HIGH);
    Clk();
  }
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Display_digit(bool positions[])
{
  for(int i=0;i<NUMBER_DIGITS;i++)
  {
    digitalWrite(sdi,positions[i]);
    Clk();
  }
}

/***************************************************************
@Name:   Write_Digit
@Brief:  Write one digit on 4-digit-7-segments display
@Params: int UserNumber ->  Set number-to-write
         boolean a      ->  Write on 1st digit
         boolean b      ->  Write on 2nd  digit
         boolean c      ->  Write on 3rd digit
         boolean d      ->  Write on 4rd digit
         boolean dot    ->  Write righted-dot
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Digit(int UserNumber, bool a, bool b, bool c, bool d, bool dot)
{  
  bool positions[4]={d,c,b,a};  
  
  Send_bit_to_dotting(dot);
  Send_bits_of_digit(UserNumber);
  Send_Shifter_bits();    
  Display_digit(positions);         
  Latch(); 
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Units(int UserNumber)
{
  int units;
  
  if(UserNumber < 10)
  {    
    units = UserNumber;  
    Write_Digit(units,0,0,0,1,NO_DOT);  
  }
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Tens(int UserNumber)
{
  int units, tens;
  
  if(UserNumber >= 10  && UserNumber < 100)
  {
    units = UserNumber%10;
    tens  = UserNumber/10;
    Write_Digit(units,0,0,0,1,NO_DOT);
    Write_Digit(tens,0,0,1,0,NO_DOT);
    
  }
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Hundreds(int UserNumber)
{
  int units, tens, hundreds;

  if(UserNumber >= 100  && UserNumber < 1000)
  {
    units = UserNumber%10;
    tens  = (UserNumber%100)/10;
    hundreds  = UserNumber/100;
    Write_Digit(hundreds,0,1,0,0,NO_DOT);
    Write_Digit(tens,0,0,1,0,NO_DOT);
    Write_Digit(units,0,0,0,1,NO_DOT);
  }  
}

/***************************************************************
@Name:   
@Brief:  
@Params: 
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Thousands(int UserNumber)
{
  int units, tens, hundreds, thousands;

  if(UserNumber >= 1000  && UserNumber < 10000)
  {            
    units = UserNumber%10;
    tens  = (UserNumber%100)/10;
    hundreds  = (UserNumber%1000)/100;
    thousands = UserNumber/1000;
    Write_Digit(thousands,1,0,0,0,NO_DOT);
    Write_Digit(hundreds,0,1,0,0,NO_DOT);
    Write_Digit(tens,0,0,1,0,NO_DOT);
    Write_Digit(units,0,0,0,1,NO_DOT);
  } 
}

/***************************************************************
@Name:   Write_Number
@Brief:  Write Float Number on Display.
         For instance,if you set:
            Write_Number(235)
     
         Then will displyed 23.50                
@Params: int UserNumber ->  Set number-to-write (0-9999)
@Return: N/A
@Status: RELEASED
@Author: A. Siordia
 ***************************************************************/
void display_4digits::Write_Number(int UserNumber)
{
  int units, tens, hundreds, thousands;
  Clear_Display();
  Write_Units(UserNumber);
  Write_Tens(UserNumber);
  Write_Hundreds(UserNumber);
  Write_Thousands(UserNumber);
}
