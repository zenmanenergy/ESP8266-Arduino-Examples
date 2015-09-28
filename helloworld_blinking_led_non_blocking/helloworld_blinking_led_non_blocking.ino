/*
 ESP8266 Blinking LED, non blocking by Steve Nelson
 This displays a blinking LED. Usually you can just
 
 It has been tested on an esp01 and esp12e
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial
  
*/


int greenLedPin = 14;

void setup() {
  Serial1.begin(115200);
  Serial1.println("");
  Serial1.println("hello world - blinking led");
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkDelay(greenLedPin, 200, 4);
}

