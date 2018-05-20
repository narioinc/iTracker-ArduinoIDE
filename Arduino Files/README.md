Arduino Support files
======

This folder contains the Arduino IDE support files:

Contents
------
* **/libraries**: folder containing additional libraries for the nrf52 core
* **/RAK8211_nrf52832_Breakout**: folder containing the RAK8211 variant files
* **boards.txt**: file containing the RAK8211 board details

Install the RAKWireless RAK8211 Board variant
--------------------
It is easy to install the RAkWireless Board variant into the IDE (For ubuntu/other linux users)

* Copy the **boards.txt** into .arduino15/packages/SparkFun/hardware/nRF5/0.2.3/boards.txt
* Copy the **RAK8211_nrf52832_Breakout** folder in the variants folder in the path .arduino15/packages/SparkFun/hardware/nRF5/0.2.3
* copy the **libraries** folder content into .arduino15/packages/SparkFun/hardware/nRF5/0.2.3/libraries

For Windows users, just search for the path that has the packages/Sparkfun folder :)

* Next, restart Arduino IDE, you should be able to see an entry for the RAK Wireless RAK8211 board. Now you can flash as you normally do

Software Serial support
-------
Based on the details in the PR request here:
https://github.com/sandeepmistry/arduino-nRF5/pull/205/files?utf8=%E2%9C%93&diff=split

I have made the necessary changes in the WInterrupt.c and header files to support the Software serial. I have tested uptil 38400 as baud rate and things work well.

Please replace the three files in your sparkfun/adafruit nrf5 core directory and enjoy SoftwareSerial.

Thanks to the awesome devs at the nrf5-arduino core.  
https://github.com/micooke
