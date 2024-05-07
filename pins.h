#ifndef PINS_H
#define PINS_H

#define POTENCIOMETER_PIN A0
#define BUZZER_PIN 3
#define SENSOR_TEMP_PIN A4
#define DS18_SENSOR_PIN A4

enum LedPinNumber
{
    d4 = 10,
    d3,
    d2,
    d1,
};

enum SwitchPinNumber
{
    s1 = 15, 
    s2,
    s3,
};

enum displayPins
{
    lchclk = 4,
    sftclk = 7,
    sdi = 8,
};

#endif

