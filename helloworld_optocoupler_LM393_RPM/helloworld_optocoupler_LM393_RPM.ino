/*
 ESP8266 LM393 Optocoupler RPM by Steve Nelson

This example extends the optocoupler example in the prerequisites. Instead of just displaying a "tick" count each
time the sensor is tripped, this one adds time component allowing for tracking revolutions per minute or RPM.

 It has been tested on an esp12e
 This example code is in the public domain

  Prerequisite Examples:
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_serial
  https://github.com/zenmanenergy/ESP8266-Arduino-Examples/tree/master/helloworld_optocoupler_LM393

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

volatile byte ticks=0;
volatile int lastTick=ticks;
long debouncing_time = 15; //Debouncing Time in Milliseconds
volatile unsigned long debounce_micros;

unsigned int rpm=0;
unsigned long timeold=0;
unsigned int ticksperturn = 20;

void tick(){
  if((long)(micros() - debounce_micros) >= debouncing_time * 1000) {
    ticks++;
    debounce_micros = micros();
  }
}



void setup() {
  Serial.begin(115200);
  pinMode(D5, INPUT);
  attachInterrupt(D5, tick, FALLING);
}

void loop() {
  //Only process this every 1 second.
  if (millis() - timeold >= 1000){
    detachInterrupt(0);
    rpm = (60 * 1000 / ticksperturn )/ (millis() - timeold)* ticks;
    timeold = millis();
    ticks = 0;
    Serial.print("RPM=");
    Serial.println(rpm);
    attachInterrupt(D5, tick, FALLING);
    
  }
}
