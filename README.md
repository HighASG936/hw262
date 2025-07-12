# hw262


## Language Index

- [English](#english)
- [Español](#spanish)

---

<a name="english"></a>
Library to use HW262 shield using on Arduino 

## Content Index
- [General View](#general-view)
- [Suitables Sensors](#suitable-sensors)
- [How connect IR receptor](#how-connect-ir-receptor)
- [Schematic](#schematic)
- [How to use library](#how-to-use-library)

<a name="general-view"></a>
## General view 

![devices](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/c9adf9c6-63b3-4169-8234-18df1d40f00c)

<a name="suitable-sensors"></a>
## Suitables Temperature Sensors and IR receptor 

### Packages 
![packages sensors](https://github.com/HighASG936/hw262/blob/main/info/pinouts.jpg)


### Datasheets
* [DS18B20 Programmable Resolution 1-Wire® Digital Thermometer](https://cdn.sparkfun.com/datasheets/Sensors/Temp/DS18B20.pdf)  
* [LM35 Precision Centigrade Temperature Sensor](https://www.ti.com/lit/ds/symlink/lm35.pdf)

### How Connect temp sensors 
When using the LM35, you must remove jumper J1 from the board and place the sensor on J4 like this:

![lm35](https://github.com/HighASG936/hw262/blob/main/info/lm35_connected.jpg)

To use the DS18 sensor, make sure that jumper J1 is on the board and connected like this:

![ds18](https://github.com/HighASG936/hw262/blob/main/info/ds18_connected.png)

<a name="how-connect-ir-receptor"></a>
## How connect IR receptor

<a name="schematic"></a>
## Schematic
![schm](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/548a8989-d12f-425e-b720-2dd60f903427)

<a name="how-to-use-library"></a>
## How to use library

After to download and install the library into your IDE, write respective header on your project. Then create invoke 
shield object by HW262:

```c++
#include <hw262.h>

void setup(){
  HW262.begin();
 HW262.display.clear();
}

void loop(){
  // Write your code here
}
```

### Led

Hw262 includes 4 independent leds named d4, d3, d2, d1. Follow snnipet show
how to use it:

```c++

HW262.ledOn(D1_PIN);     // Turn on d1
HW262.ledOff(D1_PIN);    // Turn off d1
HW262.ledToggle(D3_PIN); // Toggle state of d3

```

### Buzzer

Buzzer included on this board can be use it like this:

```c++
  HW262.buzzerOn();     // Turn on buzzer
  HW262.buzzerOff();    // Turn off buzzer
  HW262.buzzerToggle(); // Turn state of buzzer
```

### Potenciometer

The R10 showed on early schematic is connected to A0, an analog pin from Arduino UNO.
To get level voltage on A0 by potenciometer R10, use whatever those methods:

```c++
  unsigned char measure = HW262.readPinPot();    // Gate value from A0 (0-254)
  unsigned char voltage = HW262.getVoltagePot(); // Get voltage on pin A0
```


### Switches
Hw262 includes 3 independent switches named s1, s2, s3. But... how to know it was pressed?
```c++
  bool switchState = IsPressed(S1_PIN);    // Read state of switch 1

  if(switchState)
  {
    Serial.println("Don't touch this! - MC Hammer");
  }

```

### LM35 Sensor
You can connect an Temperature sensor LM35 by dedicated socket showed on early sensors picture. Be
careful with sensor connections in order to avoid damage it.

By default, hw262 library initialize the board with LM35's features. Here is an usage examples:

```c++
  unsigned char measure = HW262.tempSensor.readLm35Sensor(); // Read value on A4 (0-254)
  float temp = HW262.tempSensor.measureCentigrads()/100; // Read temperature (°C) with 2 decimals
```
Whether you omit */100* at last line and - for instance - real temperature is 23°C you will obtain 2300 as output.


### DS18 Sensor
After initializing the library, you can automatically utilize the sensor by adding this line to your code:

```c++
uint32_t temp = HW262.ds18.getTemp();
```

Whether you need to customize features of the ```HW262.ds18``` sensor, you can modify the sensor object using the inherited features from```DallasTemperature.h```.([link](https://github.com/jmchiappa/DallasTemperature) to library docs) 

### IR Receptor 

### Bluetooth & Serial port

Here is a simple example to use bluetooth:
```c++
#include <hw262.h>

uint32_t wTime = 1500:

void setup() 
{
  HW262.begin();
   HW262.display.clear();
}

void loop()
{  
  String temp = String(HW262.ds18.getTemp())+"°C";
  Serial.println(temp);
  delay(wTime);
}
```
Notice that you only have to use the Serial library from the default Arduino libraries. The hw262 library sets the serial port using HW262.begin() before it is used. You can connect any sensor with a UART port like this:

<img src="https://github.com/HighASG936/hw262/blob/main/info/serial_port.jpg" />
<img src="https://content.instructables.com/FSV/M8Q3/HX6ARQI3/FSVM8Q3HX6ARQI3.png" width="450" height="150" />

---

<a name="spanish"></a>
Librería para usar el shield HW262 en la plataforma de Arduino

<a name="indice-de-contenido"></a>
## Índice de contenido
- [Vista General](#vista-general)
- [Sensores compatibles](#sensores-compatibles)
- [Cómo conectar un receptor IR](#como-conectar-un-receptor-ir)
- [Diagrama esquemático](#diagrama-esquemático)
- [Cómo usar la librería](#como-usar-la-libreria)

<a name="vista-general"></a>
## Vista General

![devices](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/c9adf9c6-63b3-4169-8234-18df1d40f00c)

[Volver al Índice de contenido](#indice-de-contenido)

<a name="sensores-compatibles"></a>
## Sensores de temperatura y receptores IR compatibles


### Encapsulados 
![packages sensors](https://github.com/HighASG936/hw262/blob/main/info/pinouts.jpg)


### Hojas de datos
* [DS18B20 Programmable Resolution 1-Wire® Digital Thermometer](https://cdn.sparkfun.com/datasheets/Sensors/Temp/DS18B20.pdf)  
* [LM35 Precision Centigrade Temperature Sensor](https://www.ti.com/lit/ds/symlink/lm35.pdf)

<a name="como-conectar-un-receptor-ir"></a>
### Cómo conectar los sensores de temperatura
Cuando uses el sensor LM35, debes remover el jumper en el conector J1 que está en la tarjeta. 
Después, coloca el sensor en el conector J4 de la siguiente manera:
![lm35](https://github.com/HighASG936/hw262/blob/main/info/lm35_connected.jpg)

Para usar el sensor DS18, asegúrate de colocar el jumper en el conector J1 de la tarjeta, y conectar el sensor de la siguiente manera:
To use the DS18 sensor, make sure that jumper J1 is on the board and connected like this:

![ds18](https://github.com/HighASG936/hw262/blob/main/info/ds18_connected.png)

[Volver al Índice de contenido](#indice-de-contenido)

## Cómo conectar un receptor IR

[Volver al Índice de contenido](#indice-de-contenido)

<a name="diagrama-esquemático"></a>
## Diagrama esquemático


![schm](https://github.com/HighASG936/hw262-library-arduino/assets/18225112/548a8989-d12f-425e-b720-2dd60f903427)

[Volver al Índice de contenido](#indice-de-contenido)

<a name="como-usar-la-libreria"></a>
## Cómo usar la librería

After to download and install the library into your IDE, write respective header on your project. Then create invoke 
shield object by HW262:

```c++
#include <hw262.h>

void setup(){
  HW262.begin();
 HW262.display.clear();
}

void loop(){
  // Write your code here
}
```

### Led

Hw262 includes 4 independent leds named d4, d3, d2, d1. Follow snnipet show
how to use it:

```c++

HW262.ledOn(D1_PIN);     // Turn on d1
HW262.ledOff(D1_PIN);    // Turn off d1
HW262.ledToggle(D3_PIN); // Toggle state of d3

```

### Buzzer

Buzzer included on this board can be use it like this:

```c++
  HW262.buzzerOn();     // Turn on buzzer
  HW262.buzzerOff();    // Turn off buzzer
  HW262.buzzerToggle(); // Turn state of buzzer
```

### Potenciometer

The R10 showed on early schematic is connected to A0, an analog pin from Arduino UNO.
To get level voltage on A0 by potenciometer R10, use whatever those methods:

```c++
  unsigned char measure = HW262.readPinPot();    // Gate value from A0 (0-254)
  unsigned char voltage = HW262.getVoltagePot(); // Get voltage on pin A0
```


### Switches
Hw262 includes 3 independent switches named s1, s2, s3. But... how to know it was pressed?
```c++
  bool switchState = IsPressed(S1_PIN);    // Read state of switch 1

  if(switchState)
  {
    Serial.println("Don't touch this! - MC Hammer");
  }

```

### LM35 Sensor
You can connect an Temperature sensor LM35 by dedicated socket showed on early sensors picture. Be
careful with sensor connections in order to avoid damage it.

By default, hw262 library initialize the board with LM35's features. Here is an usage examples:

```c++
  unsigned char measure = HW262.tempSensor.readLm35Sensor(); // Read value on A4 (0-254)
  float temp = HW262.tempSensor.measureCentigrads()/100; // Read temperature (°C) with 2 decimals
```
Whether you omit */100* at last line and - for instance - real temperature is 23°C you will obtain 2300 as output.


### DS18 Sensor
After initializing the library, you can automatically utilize the sensor by adding this line to your code:

```c++
uint32_t temp = HW262.ds18.getTemp();
```

Whether you need to customize features of the ```HW262.ds18``` sensor, you can modify the sensor object using the inherited features from```DallasTemperature.h```.([link](https://github.com/jmchiappa/DallasTemperature) to library docs) 

### IR Receptor 

### Bluetooth & Serial port

Here is a simple example to use bluetooth:
```c++
#include <hw262.h>

uint32_t wTime = 1500:

void setup() 
{
  HW262.begin();
   HW262.display.clear();
}

void loop()
{  
  String temp = String(HW262.ds18.getTemp())+"°C";
  Serial.println(temp);
  delay(wTime);
}
```
Notice that you only have to use the Serial library from the default Arduino libraries. The hw262 library sets the serial port using HW262.begin() before it is used. You can connect any sensor with a UART port like this:

<img src="https://github.com/HighASG936/hw262/blob/main/info/serial_port.jpg" />
<img src="https://content.instructables.com/FSV/M8Q3/HX6ARQI3/FSVM8Q3HX6ARQI3.png" width="450" height="150" />

[Volver al Índice de contenido](#indice-de-contenido)


