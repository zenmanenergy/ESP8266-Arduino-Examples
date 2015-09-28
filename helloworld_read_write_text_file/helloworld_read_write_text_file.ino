/*
 ESP8266 read and write a text file by: martinayotte and Steve Nelson (it was mostly Martin! I just documented it)
 This will read and write a file to the SPIFFS file system. This particular example will write "hello world" into a text file
 that is saved in the device's file system. It then reads the file and display the words to the serial monitor.

 The file tab contains a couple functions that simplifies the process of reading and writing into a couple functions that
 handle the casting and pointers.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial



*/
#include "FS.h"

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("Read and Write to SPIFFS");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");

  //Turn on SPIFFS and mount the file system:
  Serial.println("starting SPIFFS....");
  SPIFFS.begin();

  //Write to a file in SPIFFS. 
  Serial.println("Writing to a file");
  boolean successfulWrite=fileWrite("/helloworld.txt","Hello World!");
  if (successfulWrite){
    Serial.println("file write success!");
  }else{
    Serial.println("awww CRUD. file write failed");
  }

  //Read the contents of a file from SPIFFS
  String fileContents=fileRead("/helloworld.txt");
  if (fileContents == "FILE ERROR"){
    Serial.println("awww CRUD. file read failed");
  } else{
    Serial.println("OH YEAH, here's the contents of your file:");
    Serial.println("-----------------------------");
    Serial.println(fileContents);
  }


}

void loop() {
  // put your main code here, to run repeatedly:

  
}
