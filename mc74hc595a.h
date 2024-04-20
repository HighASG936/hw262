#ifndef MC74HC595A_H
#define MC74HC595A_H

#include <Arduino.h>

#define DATA_SIZE 8

class Mc74hc595a
{
    private:
        uint8_t lchclk;
        uint8_t sftclk;
        uint8_t sdi;
        uint8_t _reset;
        uint8_t _oe;
        void Clk();
    
    public:
        Mc74hc595a(uint8_t lchclk, uint8_t sftclk, uint8_t sdi, uint8_t _reset=0, uint8_t _oe=0);
        void Send(bool* data);
        void End();
        void Reset();
        void Set();
        void Enable();
        void Disable();
};
#endif

