#ifndef pins_h
#define pins_h

#define POTENCIOMETER_PIN A0
#define BUZZER_PIN 3
#define SENSOR_TEMP_PIN A4

typedef uint8_t LedPinNumber;

static const LedPinNumber d1 = 13;
static const LedPinNumber d2 = 12;
static const LedPinNumber d3 = 11;
static const LedPinNumber d4 = 10;


typedef uint8_t SwitchPinNumber;

static const SwitchPinNumber s1 = 15;
static const SwitchPinNumber s2 = 16;
static const  SwitchPinNumber s3 = 17;


typedef uint8_t displayPins;

static const displayPins lchclk = 4;
static const displayPins sftclk = 7;
static const displayPins sdi = 8;



#endif