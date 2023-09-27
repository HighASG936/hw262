
#include "../headers/lm35.h"

lm35::lm35()
{

}

int lm35::read_sensor()
{
  return analogRead(A4);
}

int lm35::measure_centigrads()
{
    return read_sensor()/FACTOR_CONVERSION;
}
