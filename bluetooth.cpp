#include "bluetooth.h"

Bluetooth::Bluetooth()
{
    Serial.begin(9600);
    cli();
    // UCSRB |= (1 << RXCIE);
    sei();
}

/*
void Bluetooth::sendData(uint8_t type, uint8_t value)
{
 
    uint8_t data[2]={type, value};
   
    Serial.write(startTx);
    if(Serial.available())
    {   
        for(uint8_t i=0;i<sizeof(data);i++){Serial.write(data[i]);}
    }
    Serial.write(endTx);

}


void Bluetooth::send_temp(uint8_t temp)
{
    send_data(isTemp, temp);
}

void Bluetooth::send_threshold(uint8_t threshold)
{
    send_data(isThreshold, threshold);
}

uint8_t Bluetooth::get_received_threshold()
{
    return received_threshold;
}
*/