ARDUINO Examples
====================

This folder contains the example programs for the RAK8211 peripherals

Contents
----------
* **/OLEDDemo** : Demo program for the onboard OLED Screen

* **/SHT31Demo** : Demo program for the onboard SHT31 sensor
* **/LIS3DH Demo** : Demo program for the onboard LIS3DH Sensors
* **/LIS3DH Spark Demos** : Demo programs using the Sparkfun LIS3DH library with interrupt support
* **/simple_test_GPS**: Demo program for the Ublox MAX-7q GPS reciever.
* **/BLEserial**: Demo program showcasing the BLE UART example to send messages to the nrf UART profile. Use the Adafruit Bluefruit app to open the UART and see the messages.

External lib dependencies
-----

The examples mentioned require the followin libraries

* Adafruit Sensor lib : https://github.com/adafruit/Adafruit_Sensor
* Adafruit LIS3DH lib : https://github.com/adafruit/Adafruit_LIS3DH
* Adafruit SHT31 sensor: https://github.com/adafruit/Adafruit_SHT31
* Acrobotic OLED lib: https://github.com/acrobotic/Ai_Ardulib_SSD1306
* Sparkfun LIS3DH lib: https://github.com/sparkfun/SparkFun_LIS3DH_Arduino_Library
* TinyGPS lib: https://github.com/mikalhart/TinyGPS

Things to note for GPS example:
-------

The GPS example uses the SoftwareSerial. Make sure you enable software serial by following the instruction in the README file inside **Arduino Files** folder

Once enabled, ensure that the p0.19 and p0.20 pins on the nrf52 are connected to RX and TX of the GPS module and initiate SoftwareSerial object.
