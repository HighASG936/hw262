#include "../headers/pot.h"

pot::pot()
{

}

int pot::get_measure()
{
    return analogRead(pot_Pin);
}

int pot::get_voltage()
{
    int measure = get_measure();
    int voltage = (5000/1023)*measure;
    return voltage;
}
