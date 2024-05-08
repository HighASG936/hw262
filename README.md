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
