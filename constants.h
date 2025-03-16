#ifndef CONSTANTS_H
#define CONSTANTS_H

#define DEFAULT_PRECISION 1
#define SERIAL_BAUD_RATE 115200

#define MIN_DISPLAY_NUMBER -1000
#define MAX_DISPLAY_NUMBER 10000

#define MESSAGE_INVALID_NUMBER "Invalid number"
#define MESSAGE_INVALID_OFFSET "Invalid offset"
#define MESSAGE_INVALID_LENGHT_TEXT "Invalid length text"

#define SOURCE_VOLTAGE 5000L  /* mV */
#define MAX_VALUE_ADC 0x3FFL

#define MINIMUN_TEMP 18
#define MAXIMUM_TEMP 30

#define DOT 1
#define NO_DOT 0
#define NUMBER_DIGITS 4
#define NUMBER_OUTPUTS_BOTH_MC74HC595A 16

#define LM35_SENSOR_GAIN 10     /* mV/°C */

#define NUMBER_DIGITS_ON_DISPLAY 4
#define MAX_DISPLAY_POSITION 3

#endif

