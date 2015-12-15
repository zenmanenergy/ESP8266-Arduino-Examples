/*
 ESP8266 Blinking LED, non blocking by Steve Nelson
 Before you run this example, try the simple blinking LED. It uses the delay()
 function which is simpl to grasp, but causes problems because of the "blocking" 
 nature of Arduino code. What that means is that in the other example when the delay() 
 function is called the entire processor stops working until the delay timer is 
 done. So if someone were to press a button while the delay() is waiting the processor
 won't be able to handle that request.

 This example will appear to work exactly like the previous blinking led, but the underlying
 code is vastly different.

 This technique uses a non-blocking function. Look at the tabs in the IDE, it's in the "led"
 tab. Instead of using a delay, it checks the current time using the millis() function. If
 enough time has passes it changes the digitalWrite() on the pin.

 This example will also blink a light
 
 It has been tested on an esp01 and esp12e
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_blinking_led
  
*/


// on the NodeMCU board (it uses the esp8266 12e) I used
// GPIO14 which is also D5 on the board. The pins have
// multiple names, choose the "GPIO" number.
int ledPin = 1;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("blinking LED non blocking");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkDelay(ledPin, 300);
}

