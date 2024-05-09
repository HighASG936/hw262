
#include <mc74hc595a.h>
#include <math.h>
#include "hw262.h"

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

float i = 0.000;

#define MIN_DISPLAY_NUMBER -1000
#define MAX_DISPLAY_NUMBER 10000

#define MESSAGE_INVALID_NUMBER "Invalid number"
#define MESSAGE_INVALID_OFFSET "Invalid offset"
#define MESSAGE_INVALID_LENGHT_TEXT "Invalid length text"

uint8_t lchclkPin = 4;
uint8_t sftclkPin = 7;
uint8_t sdiPin    = 8;

Mc74hc595a ic(lchclkPin, sftclkPin, sdiPin);

const byte A = 0x11;
const byte B = 0xc1;
const byte C = 0x63;
const byte D = 0x85;
const byte E = 0x61; 
const byte F = 0x71;
const byte H = 0x91;
const byte I = 0xf3;
const byte J = 0x87;
const byte L = 0xe3;
const byte N = 0xd5;
const byte _N = 0x55;
const byte O = 0xc5;
const byte P = 0x31;
const byte R = 0xf5;
const byte S = 0x49;
const byte T = 0xe1;
const byte U = 0x83;
const byte Y = 0x89;
const byte hyphen = 0xfd;
const byte minus = 0xfd;
const byte degrees = 0x39;
const byte dot = 0xfe;
const byte Blank = 0xff;

const byte* numbers[10]
{
  0x03,
  0x9f, // 1111 1001
  0x25,
  0x0d,
  0x99,
  0x49,
  0x41,
  0x1f,
  0x01,
  0x09,
};


byte convertCharToSegments(char c)
{
  if(c=='A')return A;
  else if(c=='B')return B;
  else if(c=='C')return C;
  else if(c=='D')return D;
  else if(c=='E')return E;
  else if(c=='F')return F;
  else if(c=='H')return H;
  else if(c=='I')return I;
  else if(c=='J')return J;
  else if(c=='L')return L;
  else if(c=='N') return N;
  else if(c=='Ñ') return _N;
  else if(c=='O') return O;
  else if(c=='P') return P;
  else if(c=='R') return R;
  else if(c=='S') return S;
  else if(c=='T') return T;
  else if(c=='U') return U;
  else if(c=='Y') return Y;
  else if(c==' ') return Blank;
  else return Blank;
}


/**
*
*/
char* convertIntToBytes(int16_t number, bool left_zeros=false)
{
  uint32_t factor;
  uint8_t digit;
  bool startNumber = false;
  char* charNumber = new char[4];
  uint8_t position;
  byte segmentDigit;
  uint16_t absNumber = abs(number);
  
  for(int8_t i=3; i>-1; i--)
  {
    position = (3-i);
    factor = (i>1) ? (pow(10, i)+1) : pow(10, i); // correction for pow method 
    digit = absNumber / factor;  
    absNumber -= digit*factor;
    if(digit != 0 && startNumber == false)
    {
      if(number < 0)  charNumber[position-1]=minus; 
      startNumber = true;
    }
    segmentDigit = numbers[digit];
    charNumber[position] = (startNumber == true || (digit == 0 && i == 0) || left_zeros == true) ?  segmentDigit : Blank;
  }
  return charNumber;
}


/**
*
*/
void write(const char* text)
{
  uint8_t position;
  byte c;
  uint8_t len = strlen(text);

  if(len > 4)
  {
    Serial.println(MESSAGE_INVALID_LENGHT_TEXT);
    return;
  }
  
  for(int i=0; i<len;i++)
  {
    position = (3-i);
    c = convertCharToSegments(text[i]);
    ic.SendByte(c);  
    ic.SendByte(0x10 << position );
    ic.End();
  }
}

void writeInteger(int16_t number, bool left_zeros=false, uint8_t offset=0)
{
  char* n = new char[4];
  uint8_t position;

  if(offset>3)
  {
    Serial.println(MESSAGE_INVALID_OFFSET);
    return;
  }

  if(number < MIN_DISPLAY_NUMBER || number > MAX_DISPLAY_NUMBER)
  {
    Serial.println(MESSAGE_INVALID_NUMBER);
    delete[] n;
    return;
  }

  n = convertIntToBytes(number, left_zeros);    
  for(int i=0; i<4;i++)
  {
    position = (3-i)+offset;
    ic.SendByte(n[i]);  
    ic.SendByte(0x10 << position );
    ic.End();
  }
  delete[] n;
}


/**
*
*/
void write(int16_t number, bool left_zeros=false, uint8_t offset=0)
{
  writeInteger(number, left_zeros, offset);
}


/**
*
*/
void write(float number)
{
  uint8_t i;
  int16_t numberMils;

  if(number < MIN_DISPLAY_NUMBER || number > MAX_DISPLAY_NUMBER)
  {
    Serial.println(MESSAGE_INVALID_NUMBER);
    return;
  }

  if(number < 10) i = 3;
  else if(number < 100) i = 2;
  else if(number < 1000) i = 1;
  else i = 0;

  numberMils= number*round(pow(10, i));
  writeInteger(numberMils);
  write(dot, i);  
}


/**
*
*/
void write(byte symbol, uint8_t position)
{
  ic.SendByte(symbol);  
  ic.SendByte(0x10 << position);
  ic.End();
}



void setup() 
{
  Serial.begin(115200);
  HW262.begin();
  HW262.clearDisplay();
  delay(500);
  /*
  randomSeed(analogRead(0));

  for(uint8_t i=0; i<10;i++){
    float x = (float) random(0, 1000)/1000;
    for(uint32_t j=0;j<=1000;j++)write(x);
    HW262.clearDisplay();
    delay(100);
  }
*/

}


void loop()
{


  for(uint8_t pinLed=d4; pinLed<=d1; pinLed++) HW262.ledToggle(pinLed);
  delay(250);
  for(uint8_t pinLed=d4; pinLed<=d1; pinLed++) HW262.ledToggle(pinLed);

  HW262.buzzerOn();
  delay(3);
  HW262.buzzerOff();
  for(uint8_t i=0; i<500;i++)HW262.writeNumber(50);
  // delay(1000);

  // int16_t temp = HW262.ds18.getTemp();
  // for(uint32_t j=0;j<=500;j++) write(temp);
  // write(degrees, 1);
  // write(C, 0);
  //Serial.println();
  
  //int16_t i = random(-999, 9999);
  //for(uint32_t j=0;j<=500;j++) write(i);
  
  
  
 /* 
  for(int16_t i=-999; i<=9999; i++)
  {
    for(uint32_t j=0;j<=20;j++) write(i);
    HW262.ledToggle(d1);
  }
  */
/*
  for(int i=0;i<1500;i++)
  {
    write("HI");
  }


  for(int i=0;i<1500;i++)
  {
  write(0xfd, 3); // -
  write(0xfd, 2); // - 
  write(0x39, 1); // °
  write("   C");
  }
*/
}



