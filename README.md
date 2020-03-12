# Feather BLE bluetooth networking examples
## Critical Making 2020

#### Buggy_Blink
A piece of example code for debugging. Used for a lecture demonstration.

#### simple-bt-example
Example code based on Adafruit's excellent bleuart_datamode code. This simplifies things for our M0 board. Reads from an attached Force Sensor, and sends the reading to the attached phone over Bluetooth.

#### heartrate_central.js
- example of how to write a central in javascript; responds to a "notify" property
- pair it with the example sketch "heartratemonitor.ino" from the arduino examples, but remember to change your chip name

#### weather_central.js
- example of how to write a central in javascript; writes to a property and reads from a property
- example of making an API call to get live weather data
- pair it with weather_peripheral.ino

#### weather_peripheral.ino
- example of peripheral code, pairs with weather_central.js
- has a bug where it only reads one byte of the temperature; if you fix that, let me know.


### How to install required libraries for these examples: 

These examples uses [noble.js](https://github.com/noble/noble), a library for writing bluetooth communication using javascript and node.js

(There are many other ways to write bluetooth centrals, for example [this python library](https://github.com/adafruit/Adafruit_Python_BluefruitLE), or a native Android or iOS app.  You can fork the Adafruit app for [iOS](https://github.com/adafruit/Bluefruit_LE_Connect_v2) or [Android](https://github.com/adafruit/Bluefruit_LE_Connect_Android_v2) as a starting point.)

0. make sure you have node.js
([see reference here](https://www.sitepoint.com/beginners-guide-node-package-manager/))

1. npm install noble
	- If you run into problems, make sure your gcc is on the right path: 
	- $ which gcc
	- should show: /usr/bin/gcc
	- if it does not, do this: $ export PATH=/usr/bin:$PATH
	- [source](https://github.com/sandeepmistry/node-xpc-connection/issues/2)
2. npm install request
	- this library lets you make API calls

 
