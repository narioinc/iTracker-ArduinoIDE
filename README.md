RAK Wireless RAK8211 iTracker Boards
========================================

[[RAK Wireless RAK8211 iTracker Boards]](https://www.aliexpress.com/item/RAK8211-Hybrid-Location-Tracker-LoRa-Bluetooth-5-0-Beacon-GPS-Sensors-LCD-LoRaWAN-1-0-2/32849717052.html)

The nRF52832 is [Nordic Semiconductor's](https://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF52832) latest multiprotocol radio system-on-chip (SoC). It's half microcontroller, with a list of features including 32 configurable I/O pins, SPI, I<sup>2</sup>C, UART, PWM, ADC's, 512kB flash, and 64kB RAM. And, it's half 2.4GHz multiprotocol radio, supporting **Bluetooth low energy** (BLE), **ANT**, and Nordic's proprietary 2.4GHz ultra low-power wireless communication -- it even features on-chip NFC tag support.

RAK8211-NB is a versatile developer board aimed at aiding in quick prototypes using NB-IOT. The board includes a vast array of connectivity options (NB-IoT, BLE 5.0 and GPS) and sensors like an accelerometer, a light sensor and a barometric sensor. At the heart of the module is the venerable Nordic NRF52832 BLE processor. The NB-IoT connectivity is provided by the Quectel BC95 module. The RAK8211-NB module is Arduino friendly and can be programmed using the IDE. The board also provides SWD interface for programming the NRF52832 core. The combination of BLE and NB-IoT provides flexible low power consumption development along with myriad of application option ranging from telemetry to live tracking and environment sensing. With RAK8211 tracker board the sky is the limit for your ideas !!

Features & Applications
Arduino Compatible–Host controller NRF52832 has been widely used in Arduino environment
Integrated Quectel BC95 NB-IoT wireless communication Module
* Integrated Quectel L70 GPS/GLONASS  Module with Assisted-GPS
* Integrated LIS3DH ultra low-power, high performance 3-axes “nano” accelerometer
* Integrated LIS2MDL ultra-low-power, high-performance 3-axis digital magnetic sensor.
* Integrated BME280 ultra low-power, high linearity, high accuracy sensors for pressure, humidity and temperature
* Integrated OPT3001 that measures the intensity of visible ligh
* Size 43mm x 38mm x 18mmOperation temperature -40°C to +85°CPower supply 3.5V to 18V(power at solar panel connector P2).


Repository Contents
-------------------
* **/Firmware** - Serial bootloader source and hex files
* **/Arduino Files** - Arduino IDE Support Files
* **/examples** - Arduino examples for onboard peripherals


Documentation
--------------
* **[Arduino Hardware Definitions](https://github.com/sparkfun/Arduino_Boards/)** - Arduino cores and tools for the nRF52.

Download and Install the Board Package
-------------
The nRF52 Arduino cores are based on the great work by sandeepmistry. Sparkfun has added nRF52832 Breakout Board compatibility to his board files, and added an extra tool to enable serial bootloading.

Since the RAK wireless RAK8211 is just having a few extra LEDs and Buttons that the Sparkfun board, it was easy to port the bootloader functionality.

* To install support for the nRF52 board in Arduino, begin by opening your Arduino preferences (File > Preferences). Then copy and paste the URL below into the “Additional Board Manager URLs” text box.

https://raw.githubusercontent.com/sparkfun/Arduino_Boards/nrf5/IDE_Board_Manager/package_sparkfun_index.json

* Then hit OK, and navigate to the Tools > Board > Boards Manager… tool. A search for “nRF52” should turn up a SparkFun nRF52 Boards result. Select that and click install.
* The install may take a few minutes – the package includes arm-gcc and a few other tools totaling around 100 MB. Once the installation is complete, go to Tools > Board and select “SparkFun nRF52832 Breakout” under the “Nordic Semiconductor nRF5 Boards” section.
* You can now create Sketches using the BLEPeripheral library as well and compile them for the RAK8211 board.

Install the RAKWireless RAK8211 Board variant
--------------------
It is easy to install the RAkWireless Board variant into the IDE (For ubuntu/other linux users)

* Copy the Boards.txt into .arduino15/packages/SparkFun/hardware/nRF5/0.2.3/boards.txt
* Copy the RAK8211_nrf52832_Breakout folder in the variants folder in the path .arduino15/packages/SparkFun/hardware/nRF5/0.2.3

For Windows users, just search for the path that has the packages/Sparkfun folder :)

* Next, restart Arduino IDE, you should be able to see an entry for the RAK Wireless RAK8211 board. Now you can flash as you normally do




Build and use the bootloader
-------------------
To build the bootloader follow the steps below

* Clone the Repository
* cd to nRF52832_Breakout folder and do make clean
* Then, execute the command "make sfe_nrf52832_dfu"
* Once the program successfully builds, just connect your RAK8211 over SWD interface using your JLink module
* execute the command "./flash_bootloader.sh"

Board Hardware details
-------------------
* SW3 is the board reset switch
* SW1 is the board bootloader switch
* LED6 is the bootloader time-bomb LED (currently not working, fix on the way)

How to enter Serial-Bootloader mode
-------------
When you want to enter bootloader mode, keep **SW1** pressed, then press **SW3** and release **SW3** after a second and then release **SW1**.


Product Versions
----------------
* [RAK Wireless RAK8211 nRF52832 (RAK8211)](https://www.aliexpress.com/item/RAK8211-Hybrid-Location-Tracker-LoRa-Bluetooth-5-0-Beacon-GPS-Sensors-LCD-LoRaWAN-1-0-2/32849717052.html)- Initial release of the RAK Wireless RAK8211 nRF52832 Breakout

Version History
---------------
* v1.0 Support for the RAK8211 board. LED indicator for bootloader is not working. fix on the way !!

License Information
-------------------
This product is completely _**open source**_! Please fork and provide your valuable feedback.

Special Thanks !!!!!
-------------------
THANKS a bunch to the awesome guys at Sparkfun for their original serial bootloader that i have reused for this board.

Their git repo is here:
https://github.com/sparkfun/nRF52832_Breakout
