/*
 ESP8266 Non-blocking Wifi Connect by Steve Nelson
 This connects to a wifi router but does not use any delay() functions. So while 
 the ESP is attempting to connect to the router you can still run other functions.
 I have included it so you can understand the difference between "blocking" and
 "non-blocking" code. Whenever you use a delay() function the ENTIRE processor is delayed
 so if you delay the processor when a person presses a button, the arduino won't be
 able to process whether there is a button push.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_blinking_led
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_blinking_led_non_blocking



*/

#include <ESP8266WiFi.h>

//these are your wifi router's name and password
String internetSSID="";
String internetpwd="";

//these are used for the timer function below
unsigned long interval = 500;
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.println("------------------------");
  Serial.println("ESP8266 Arduino Examples");
  Serial.println("WiFi connect, non blocking");
  Serial.println("by Steve Nelson");
  Serial.println("------------------------");
}

int lastWiFiStatus=-1;
void loop() {
  //these two functions are below
  wifiConnect();
  doSomethingWhileYouWait();
}






void doSomethingWhileYouWait(){
  
  //This IF statement is just a timer, it compares two times in milliseconds, if enough time has passed it
  //executes the code inside the if statement.
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    //This demonstrates that you can run code while the ESP is attemptting to connect to the router
    if (WiFi.status() != WL_CONNECTED){
      Serial.println("I can walk and chew gum at the same time!");
    }
  }
}

void wifiConnect(){
  //by comparing the last status to the current status
  //this IF statement is only executed if the wifi status has changed.
  if (lastWiFiStatus!=WiFi.status()){
    if (WiFi.status() == WL_CONNECTED){
      Serial.println("Connected!!");
      Serial.print(WiFi.localIP());
    } else{
      //If the wifi status has changed and it's not currently connected, begin the connection.
      Serial.println("No Connection...attempting to connect");
      WiFi.begin(internetSSID.c_str(), internetpwd.c_str());
    }
    lastWiFiStatus=WiFi.status();
  }
}

