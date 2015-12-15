/**
 * httpUpdate.ino
 *
 *  Created on: 27.11.2015
 *
 */

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;

void setup() {
  
  USE_SERIAL.begin(115200);
  // USE_SERIAL.setDebugOutput(true);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  WiFiMulti.addAP("dd-wrt", "");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("connected");
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    //t_httpUpdate_return ret = ESPhttpUpdate.update("http://192.168.1.112/personalProjects/fridgeAlive/api/1.4/bin/helloworld_restart.cpp.bin");
    t_httpUpdate_return ret = ESPhttpUpdate.update("fridgealive.com", 80, "/api/firmware.php", "1.3.0");
    //t_httpUpdate_return  ret = ESPhttpUpdate.update("https://server/file.bin");

    switch (ret) {
      case HTTP_UPDATE_FAILED:
        USE_SERIAL.println("HTTP_UPDATE_FAILD");
        break;

      case HTTP_UPDATE_NO_UPDATES:
        USE_SERIAL.println("HTTP_UPDATE_NO_UPDATES");
        break;

      case HTTP_UPDATE_OK:
        USE_SERIAL.println("HTTP_UPDATE_OK");
        Serial.println(digitalRead(0));
        Serial.println(digitalRead(2));
        Serial.println(digitalRead(15));
        digitalWrite(0,HIGH);
        digitalWrite(2,HIGH);
        digitalWrite(15,LOW);
        Serial.println(digitalRead(0));
        Serial.println(digitalRead(2));
        Serial.println(digitalRead(15));
        USE_SERIAL.println("restarting");
        delay(500);
        ESP.restart();
        break;
    }
  }
}

void loop() {
  // wait for WiFi connection

}

