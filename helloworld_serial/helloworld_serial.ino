/*
 ESP8266 Serial Print by Steve Nelson
 This displays "Hello World" in the Serial monitor.
 
 It has been tested on an esp01 and esp12e using Arduino 1.6.8 and Arduino ESP8266 core version 2.2.0
 This example code is in the public domain
 
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("Hello world serial print");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
}

void loop() {
  //This loops until the end of time
  Serial.println("hello world");
  delay(300);

}
