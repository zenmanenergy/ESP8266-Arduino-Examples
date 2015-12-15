/*
 ESP8266 blinking LED by Steve Nelson
 This turns an LED on and off. It uses an inefficient technique that will pause ALL of your 
 code. I have included it so you can understand the difference between "blocking" and
 "non-blocking" code. Whenever you use a delay() function the ENTIRE processor is delayed
 so if you delay the processor when a person presses a button, the arduino won't be
 able to process whether there is a button push.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial



*/

// on the NodeMCU 1.0 board (it uses the esp8266 12e) I used
// GPIO2 which is also D4 on the board. The pins have
// multiple names, choose the "GPIO" number.
int ledPin = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("blinking LED");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("LOW");
  digitalWrite(ledPin,LOW);
  delay(1000);
  Serial.println("HIGH");
  digitalWrite(ledPin,HIGH);
  delay(1000);
  
}

