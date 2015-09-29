/* 
 ESP8266 CheckFlashConfig by Markus Sattler
 
 This sketch tests if the EEPROM settings of the IDE match to the Hardware

 Start by setting the flash size to 512K (64K SPIFFS). Then upload this code and
 open the serial monitor. It will tell you whether your upload size is correct
 or too small. I have found that on the older esp01s (blue boards) they are 512K
 whereas the esp01s (black boards) are 1M. If you upload with the wrong flash
 size the boards crash at random times. 
 
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial
 */

#include <ESP.h>

void setup(void) {
    Serial.begin(115200);
}

void loop() {

    uint32_t realSize = ESP.getFlashChipRealSize();
    uint32_t ideSize = ESP.getFlashChipSize();
    FlashMode_t ideMode = ESP.getFlashChipMode();

    Serial.printf("Flash real id:   %08X\n", ESP.getFlashChipId());
    Serial.printf("Flash real size: %u\n\n", realSize);

    Serial.printf("Flash ide  size: %u\n", ideSize);
    Serial.printf("Flash ide speed: %u\n", ESP.getFlashChipSpeed());
    Serial.printf("Flash ide mode:  %s\n", (ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN"));

    if(ideSize != realSize) {
        Serial.println("Flash Chip configuration wrong!\n");
    } else {
        Serial.println("Flash Chip configuration ok.\n");
    }

    delay(5000);
}
