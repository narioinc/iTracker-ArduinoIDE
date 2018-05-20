// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

/*
 * Serial Port over BLE
 * Create UART service compatible with Nordic's *nRF Toolbox* and Adafruit's *Bluefruit LE* iOS/Android apps.
 *
 * BLESerial class implements same protocols as Arduino's built-in Serial class and can be used as it's wireless
 * replacement. Data transfers are routed through a BLE service with TX and RX characteristics. To make the
 * service discoverable all UUIDs are NUS (Nordic UART Service) compatible.
 *
 * Please note that TX and RX characteristics use Notify and WriteWithoutResponse, so there's no guarantee
 * that the data will make it to the other end. However, under normal circumstances and reasonable signal
 * strengths everything works well.
 */


// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>
#include "BLESerial.h"

#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

// define pins (varies per shield/board)
#define BLE_REQ   10
#define BLE_RDY   2
#define BLE_RST   9

// create ble serial instance, see pinouts above
BLESerial BLESerial(BLE_REQ, BLE_RDY, BLE_RST);
TinyGPS gps;
SoftwareSerial ss(19, 20);

void setup() {
  // custom services and characteristics can be added as well
  BLESerial.setLocalName("UART");

  Serial.begin(115200);
  BLESerial.begin();

  pinMode(31, OUTPUT);
  Serial.begin(115200);
  ss.begin(9600);
  
  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
  digitalWrite(31, HIGH);

  Wire.begin();  
  oled.init();  
  oled.clearDisplay(); 
  
}

void loop() {
  BLESerial.poll();

  //forward();
  //loopback();
  //spam();

bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      BLESerial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  if (newData)
  {
    oled.clearDisplay();
    float flat = 0.0, flon = 0.0;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    BLESerial.print("LAT=");
    BLESerial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    oled.setTextXY(0,0);              // Set cursor position, start of line 0
    oled.putFloat(flat);
    BLESerial.print(" LON=");
    BLESerial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    oled.setTextXY(1,0);              // Set cursor position, start of line 1
    oled.putFloat(flon);
    BLESerial.print(" SAT=");
    BLESerial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    BLESerial.print(" PREC=");
    BLESerial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
  }
  
  gps.stats(&chars, &sentences, &failed);
  BLESerial.print(" CHARS=");
  BLESerial.print(chars);
  BLESerial.print(" SENTENCES=");
  BLESerial.print(sentences);
  BLESerial.print(" CSUM ERR=");
  BLESerial.println(failed);
  if (chars == 0)
    BLESerial.print("** No characters received from GPS: check wiring **");

   
}


// forward received from Serial to BLESerial and vice versa
void forward() {
  if (BLESerial && Serial) {
    int byte;
    while ((byte = BLESerial.read()) > 0) Serial.write((char)byte);
    while ((byte = Serial.read()) > 0) BLESerial.write((char)byte);
  }
}

// echo all received data back
void loopback() {
  if (BLESerial) {
    int byte;
    while ((byte = BLESerial.read()) > 0) BLESerial.write(byte);
  }
}

// periodically sent time stamps
void spam() {
  if (BLESerial) {
    BLESerial.print(millis());
    BLESerial.println(" tick-tacks!");
    delay(1000);
  }
}
