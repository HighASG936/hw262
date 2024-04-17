
#include "hw262.h"

void setup()
{
    HW262.begin();
    HW262.clearDisplay();
}


void loop()
{
    HW262.writeNumber(HW262.getVoltagePot());
    delay(5);
}