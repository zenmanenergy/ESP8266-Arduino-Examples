/*
 ESP8266 Hello World EEPROM by Steve Nelson
 EEPROM allows for persistant data even if the ESP loses power. It's kind of a pain in the
 ass to work with though. So I made a useful set of functions to work with it. I haven't
 converted this into a a C library yet. I'll do that soon.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain, use it however you want. 

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial



*/

#include <EEPROM.h>
#include "./eepromSimple.h"
eepromSimple eeprom;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("EEPROM examples");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
  eeprom.begin(512);
  //eeprom.clear();
  eeprom.set("firstname","nicole");
  eeprom.set("lastname","fewell");
  Serial.println(eeprom.list());
  eeprom.remove("lastname");
  Serial.println(eeprom.list());
  eeprom.set("lastname","nelson");
  Serial.println(eeprom.list());
  
  
  eeprom.setFromList("&ssid=makerspaces&ssidpwd=boops&owner=Beau&email=beau@turner.com");
  Serial.println(eeprom.list());
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
