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

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World - EEPROM");
  EEPROM.begin(512);

  String allEEPROMVariables=eepromList();
  Serial.println(allEEPROMVariables);
  
  eepromSet("firstname","Steve");
  eepromSet("lastname","Nelson");
  String firstName=eepromGet("firstname");
  String lastName=eepromGet("lastname");
  Serial.print("hello ");
  Serial.println(firstName);
  Serial.println("hello..");
  Serial.print("Goodbye Mr. ");
  Serial.println(lastName);
  
  //Now delete the last name. Restart the device and you'll see it is not in the eepromList();
  eepromDelete("lastname");
  Serial.println("Deleted lastname from eeprom");
}

void loop() {
  // put your main code here, to run repeatedly:

}
