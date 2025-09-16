```
To build a Temperature and humidity monitoring system and
transmitting the sensor data using ESP NOW protocol.
```
What is ESP NOW?

ESP-NOW, a connectionless protocol developed by Espressif for
the ESP32 and ESP08266 microcontrollers. With ESP-NOW we can
build a private network without WiFi or a Router.

This is a separate network from the WiFi network and can only be
used by ESP-type microcontrollers. The protocol is called ESP-
NOW.

When Initiators/transmitter communicate with
Responders/receivers, they need to know the Responder’s MAC
Address.
A MAC, or Media Access Control, Address is a unique 6-digit
hexadecimal number assigned to every device on a network.

# Aim

# Real World Application

# Concepts

```
Greenhouse Monitoring
Different zones monitored for soil and air temperature.
ESP-NOW nodes can cover large areas without Wi-Fi routers.
```
```
Hazard Detection
Sensors distributed in warehouses or mines to detect
abnormal temperature rises
ESP-NOW ensures fast peer-to-peer alerts without internet
Air quality monitoring system
Project can be extended to monitor air quality by including
some gas sensors (MQ sensors)
```

How this project works

The temperature and humidity data is measured by multiple DHT
sensors at different locations and the data sent via ESP NOW to
one ESP receiver/responder for monitoring.

```
ESP 32 Module
DHT 11 Temperature and Humidity Sensor
LCD I2C Display
Jumper Wires
Bread Board
```
# Components

```
DHT 11
```
```
LCD
DHT 11
```
```
ESP 32
```
```
ESP 32
```
```
ESP 32
```
```
TEMP & HUMIDITY
```
```
DATA SENT VIA
ESP NOW
```
```
TEMP & HUMIDITY
```
```
DATA
```
```
DATA
INITIATOR 2
```
```
RESPONDER
```
```
DDISPLAATA ON LYINGCD
```
```
INITIATOR 1
```

# DHT 11 WORKING

```
DHT11 sensor consists of a capacitive humidity sensing element
and a thermistor for sensing temperature.
```
```
The humidity sensing capacitor has two electrodes with a
moisture holding substrate as a dielectric between them. Change
in the capacitance value occurs with the change in humidity
levels. The IC measure, process this changed resistance values
and change them into digital form.
```
```
Lower Electrode
```
```
Internal structure of humidity Sensor
```
```
Moisture Holding
substrate
```
```
Upper Electrode
```

For measuring temperature this sensor uses a Negative
Temperature coefficient thermistor, which causes a decrease in
its resistance value with increase in temperature. To get larger
resistance value even for the smallest change in temperature, this
sensor is usually made up of semiconductor ceramics or
polymers.

```
The temperature range of DHT 11 is from 0 to 50 degree
Celsius with a 2 - degree accuracy.
Humidity range of this sensor is from 20 to 80 % with 5 %
accuracy.
The sampling rate of this sensor is 1 Hz .i.e. it gives one
reading for every second.
DHT 11 is small in size with operating voltage from 3 to 5
volts.
The maximum current used while measuring is 2. 5 mA.
```

# Connections

## DHT 11

## LCD I2C

```
TRANSMITTER CIRCUIT
```
```
RECEIVER CIRCUIT
```
### VCC TO 5 VOLT

### GND TO GROUND

### OUT TO PIN 4 OF ESP 32 (INITIATOR BOARD)

### VCC TO 5 VOLT

### GND TO GROUND

### SDA TO PIN 4 ESP 32 ( RECEIVER BOARD)

### SCL TO PIN 5 ESP 32 ( RECEIVER BOARD)

```
DHT 11
```
```
ESP 32
```
```
ESP 32
LCD I2C
```

# Circuit Diagram

```
DHT 11
```
```
ESP 32
```

