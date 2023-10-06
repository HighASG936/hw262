#include "../headers/relay.h"

relay::relay()
{
    pinMode(relayPin, OUTPUT);
    relayOff();
}


void relay::relayOn()
{
    digitalWrite(relayPin, HIGH);
}


void relay::relayOff()
{
    digitalWrite(relayPin, LOW);
}
