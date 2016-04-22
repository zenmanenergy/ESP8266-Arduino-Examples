/*
 ESP8266 LM393 Optocoupler by Steve Nelson


 It has been tested on an esp01 and esp12e
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial

NodeMCU pin mappings. Pin numbers written on the board itself do not correspond to ESP8266 GPIO pin numbers.
Constants are defined to make using this board easier:

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

 */

int direction=1; // forward=1 and backwards=-1
volatile int ticks=0;
volatile int lastTick=ticks;
long debouncing_time = 15; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;

void tick(){
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    if (direction=1){
      ticks++;
    }else{
      ticks--;
    }
    last_micros = micros();
  }

}

void setup() {
  Serial.begin(115200);
  attachInterrupt(D5, tick, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (lastTick != ticks){
    Serial.println(ticks);
    lastTick=ticks;
  }
}
