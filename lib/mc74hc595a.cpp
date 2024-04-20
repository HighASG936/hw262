
#include "mc74hc595a.h"

/**
 * @brief Construct a new Mc74hc595a:: Mc74hc595a object
 * 
 * @param lchclk 
 * @param sftclk 
 * @param sdi 
 * @param _reset 
 */
Mc74hc595a::Mc74hc595a(uint8_t lchclk, uint8_t sftclk, uint8_t sdi, uint8_t _reset, uint8_t _oe):
	lchclk(lchclk),
	sftclk(sftclk),
	sdi(sdi),
	_reset(_reset),
	_oe(_oe)
{
	if(_reset != 0)
	{
		pinMode(_reset, OUTPUT);
		Set();
	}

	if(_oe != 0)
	{
		pinMode(_reset, OUTPUT);
		Enable();
	}	

	pinMode(sftclk, OUTPUT);
	pinMode(lchclk, OUTPUT);
  pinMode(sdi, OUTPUT);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Clk()
{
  digitalWrite(sftclk,LOW);
  digitalWrite(sftclk,HIGH);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Latch()
{
  digitalWrite(lchclk, LOW);
  digitalWrite(lchclk, HIGH);
}


/**
 * @brief 
 * 
 * @param data 
 */
void Mc74hc595a::Send(bool* data)
{
	for(uint8_t i=0;i<DATA_SIZE;i++)
  {
    digitalWrite(sdi,data[i]);
    Clk();
  }
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::End()
{
  digitalWrite(lchclk,LOW);
  digitalWrite(lchclk,HIGH);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Reset()
{
	digitalWrite(_reset,LOW);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Set()
{
	digitalWrite(_reset,HIGH);
}

/**
 * @brief 
 * 
 */
void Mc74hc595a::Enable()
{
	digitalWrite(_oe, LOW);
}

/**
 * @brief 
 * 
 */
void Mc74hc595a::Disable()
{
	digitalWrite(_oe, HIGH);
}
