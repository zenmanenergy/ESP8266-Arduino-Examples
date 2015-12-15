/*
 ESP8266 simple file read/write by Steve Nelson
 This demonstrates out to do very simple processing on text files in SPIFFS. It demonstrates
 three functions: reading, writing and removing. 
  
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
  Serial.println("read/write/remove text file from SPIFFS");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");

  //this just flushes out the Serial port. to be honest, I don't know why this is done1
  for (uint8_t t = 2; t > 0; t--) {
    Serial.printf("[BOOTING] WAIT %d...\n", t);
    Serial.flush();
    delay(500);
  }

  //remove the file from SPIFFS
  //removeFile("/helloworld.txt");
  Serial.println();
  Serial.println();

  //write a file into SPIFFS with the text: "hello world"
  writeFile("/helloworld.txt", "hello world");
  Serial.println();
  Serial.println();

  //read a file from SPIFFS
  String contents=readFile("/helloworld.txt");
  Serial.print("file contents:");
  Serial.println(contents);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
