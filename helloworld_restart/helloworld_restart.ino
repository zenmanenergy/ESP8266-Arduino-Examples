/*
 ESP8266 Serial Print by Steve Nelson
 This displays "Hello World" in the Serial monitor.
 
 It has been tested on an esp01 and esp12e
 This example code is in the public domain
 
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("boot");
  Serial.flush();
  
  delay(1000);
  Serial.println("rebooting");
  delay(500);
  ESP.restart();
}

void loop() {
  
}
