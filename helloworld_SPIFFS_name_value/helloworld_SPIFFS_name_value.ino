/*
 ESP8266 name value file read/write by Steve Nelson
 This demonstrates out to store simple name=value data in a text file in SPIFFS. It
 stores each name/value on it's only line.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial



*/
#include <FS.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPIFFS.begin();
  Serial.println();
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("name=value pairs stored in a text file with SPIFFS");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");

  //this just flushes out the Serial port. to be honest, I don't know why this is done. ha!
  for (uint8_t t = 2; t > 0; t--) {
    Serial.printf("[BOOTING] WAIT %d...\n", t);
    Serial.flush();
    delay(500);
  }


  //uncomment this if you want to start over and remove the file completely.
  //removeFile("/config.txt");
  
  //read a file from SPIFFS
  String contents=readFile("/config.txt");
  Serial.print("file contents:");
  Serial.println(contents);
  Serial.println();
  
  
  dataSet("ssid","mywifi");
  dataSet("ssidPass","password");
  
  String ssid=dataGet("ssid");
  Serial.println("-----");
  Serial.print("ssid:");
  Serial.println(ssid);
  Serial.println();
  
  String ssidPass=dataGet("ssidPass");
  Serial.println("-----");
  Serial.print("ssidPass:");
  Serial.println(ssidPass);

  dataRemove("ssidPass");
  
  String ssidPass2=dataGet("ssidPass");
  Serial.println("-----");
  Serial.print("ssidPass:");
  Serial.println(ssidPass2);
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
