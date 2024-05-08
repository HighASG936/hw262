# hw262
Library to use HW262 shield using on Arduino 

## General view 

![devices](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/c9adf9c6-63b3-4169-8234-18df1d40f00c)


## Suitables Temperature Sensors

### Packages 
![packages sensors](https://github.com/HighASG936/hw262/blob/main/info/pinouts.jpg)


### Datasheets
* [DS18B20 Programmable Resolution 1-Wire® Digital Thermometer](https://cdn.sparkfun.com/datasheets/Sensors/Temp/DS18B20.pdf)  
* [LM35 Precision Centigrade Temperature Sensor](https://www.ti.com/lit/ds/symlink/lm35.pdf)

### How Connect it
When using the LM35, you must remove jumper J1 from the board and place the sensor on J4 like this:

![lm35](https://github.com/HighASG936/hw262/blob/main/info/lm35_connected.jpg)

To use the DS18 sensor, make sure that jumper J1 is on the board and connected like this:

![ds18](https://github.com/HighASG936/hw262/blob/main/info/ds18_connected.png)


## Schematic
![schm](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/548a8989-d12f-425e-b720-2dd60f903427)

# How to use library

After to download and install the library into you IDE, write respective header on your project. Then create invoke 
shield object by HW262:

```c++
#include <hw262.h>

void setup(){
  HW262.begin();
}

void loop(){
  // Write your code here
}
```

## Led

Hw262 includes 4 independent leds named d4, d3, d2, d1. Follow snnipet show
how to use it:

```c++

HW262.ledOn(d1);     // Turn on d1
HW262.ledOff(d1);    // Turn off d1
HW262.ledToggle(d3); // Toggle state of d3

```

## Buzzer

Buzzer included on this board can be use it like this:

```c++
  HW262.buzzerOn();     // Turn on buzzer
  HW262.buzzerOff();    // Turn off buzzer
  HW262.buzzerToggle(); // Turn state of buzzer
```

## Potenciometer

The R10 showed on early schematic is connected to A0, an analog pin from Arduino UNO.
To get level voltage on A0 by potenciometer R10, use whatever those methods:

```c++
  unsigned char measure = HW262.readPinPot();    // Gate value from A0 (0-254)
  unsigned char voltage = HW262.getVoltagePot(); // Get voltage on pin A0
```


## Switches
Hw262 includes 3 independent switches named s1, s2, s3.But... how to know it was pressed?
```c++
  bool switchState = IsPressed(s1);    // Read state of switch 1

  if(switchState)
  {
    Serial.println("Don't touch this! - MC Hammer");
  }

```

## LM35 Sensor
You can connect an Temperature sensor LM35 by dedicated socket showed on early sensors picture. Be
careful with sensor connections in order to avoid damage it.

By default, hw262 library initialize the board with LM35's features. Here is an usage examples:

```c++
  unsigned char measure = HW262.tempSensor.readLm35Sensor(); // Read value on A4 (0-254)
  float temp = HW262.tempSensor.measureCentigrads()/100; // Read temperature (°C) with 2 decimals
```
Whether you omit */100* at last line and - for instance - real temperature is 23°C you will obtain 2300 as output.

## Future Features

1. Availibity to:
  + Bluetooth
  + Temperature Sensor DS18
  + Infrared receiver
  + Voice module
  + APC220 wireless module

2. Enable write letters on display
3. Enable write float numbers
4. Custom display characters

