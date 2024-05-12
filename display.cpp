
#include "hw262.h"

Mc74hc595a Display::ic(LCHCLK_PIN, SFTCLK_PIN, SDI_PIN);

const byte Display::A = 0x11;
const byte Display::B = 0xc1;
const byte Display::C = 0x63;
const byte Display::D = 0x85;
const byte Display::E = 0x61; 
const byte Display::F = 0x71;
const byte Display::H = 0x91;
const byte Display::I = 0xf3;
const byte Display::J = 0x87;
const byte Display::L = 0xe3;
const byte Display::N = 0xd5;
const byte Display::_N = 0x55;
const byte Display::O = 0xc5;
const byte Display::P = 0x31;
const byte Display::R = 0xf5;
const byte Display::S = 0x49;
const byte Display::T = 0xe1;
const byte Display::U = 0x83;
const byte Display::Y = 0x89;
const byte Display::hyphen = 0xfd;
const byte Display::minus = 0xfd;
const byte Display::degrees = 0x39;
const byte Display::dot = 0xfe;
const byte Display::Blank = 0xff;

const byte* Display::numbers[10]
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


/**
 * @brief 
 * 
 * @param c 
 * @return byte 
 */
byte Display::convertCharToSegments(char c)
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
 * @brief 
 * 
 * @param number 
 * @param left_zeros 
 * @return char* 
 */
char* Display::convertIntToBytes(int16_t number, bool left_zeros)
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
 * @brief 
 * 
 * @param text 
 */
void Display::write(const char* text)
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


/**
 * @brief 
 * 
 * @param number 
 * @param left_zeros 
 * @param offset 
 */
void Display::writeInteger(int16_t number, bool left_zeros, uint8_t offset)
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
 * @brief 
 * 
 * @param number 
 * @param left_zeros 
 * @param offset 
 */
void Display::write(int16_t number, bool left_zeros, uint8_t offset)
{
  writeInteger(number, left_zeros, offset);
}


/**
 * @brief 
 * 
 * @param number 
 */
void Display::write(float number)
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
 * @brief 
 * 
 * @param symbol 
 * @param position 
 */
void Display::write(byte symbol, uint8_t position)
{
  ic.SendByte(symbol);  
  ic.SendByte(0x10 << position);
  ic.End();
}

