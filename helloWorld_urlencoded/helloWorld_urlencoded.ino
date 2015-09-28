/*
 ESP8266 Hello World urlencode by Steve Nelson
 URLEncoding is used all the time with internet urls. This is how urls handle funny characters
 in a URL. For example a space is: %20

 These functions simplify the process of encoding and decoding the urlencoded format.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain, use it however you want. 

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial



*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("Hello world urlencoded example");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
  
  String encoded=urlencode("Hello\nWorld");
  Serial.println(encoded);

  String decoded=urldecode(encoded);
  Serial.println(decoded);
}


void loop() {
  // put your main code here, to run repeatedly:
  
}




