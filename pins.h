#ifndef PINS_H
#define PINS_H

#if defined(__AVR_ATmega328P__) // Arduino Uno

#define POTENTIOMETER_PIN A0
#define BUZZER_PIN 3
#define SENSOR_TEMP_PIN A4
#define DS18_SENSOR_PIN A4

// Display pins
#define LCHCLK_PIN 4
#define SFTCLK_PIN 7
#define SDI_PIN    8

// Led pins
#define D4_PIN 10
#define D3_PIN 11
#define D2_PIN 12
#define D1_PIN 13

// Switch pins
#define S1_PIN 15
#define S2_PIN 16
#define S3_PIN 17

#elif defined(__AVR_ATmega2560__) // Arduino Mega

#define POTENTIOMETER_PIN A0
#define BUZZER_PIN 5
#define SENSOR_TEMP_PIN A8
#define DS18_SENSOR_PIN A8

// Display pins
#define LCHCLK_PIN 22
#define SFTCLK_PIN 23
#define SDI_PIN    24

// Led pins
#define D4_PIN 30
#define D3_PIN 31
#define D2_PIN 32
#define D1_PIN 33

// Switch pins
#define S1_PIN 40
#define S2_PIN 41
#define S3_PIN 42

#else
#error "Unsupported board. Update the pin definitions in pins.h."
#endif

typedef uint8_t LedPinNumber;
typedef uint8_t SwitchPinNumber;

#endif
