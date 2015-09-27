Arduino examples for ESP8266 WiFi chip
===========================================

The purpose of this repository is to display "Hello World" style examples for the ESP8266 Arduino board.
Historically the first program you learn to write simply displays the words "Hello World" on the screen. The reason
for printing these words is to simply demonstrate that you have properly setup a programming environment. In the world
of internet of things devices such as the ESP8266 you may blink an LED or a make a motor move.

These examples are meant to be easy to comprehed by performing only a single concept. Many of the examples will
build on knowledge from the other examples, when this is the case, we will try to list the other examples to run
first.

### Arduino IDE Installation ###
Before these examples will work, get the latest Arduino IDE here:
https://github.com/esp8266/Arduino

### Which one should I start with? ###

Start with "helloworld_serial" All this program does is display "Hello World" in the serial monitor over and over again.
This ensures your arduino IDE is setup properly.



Contributing

For minor fixes or new examples, submit a pull request. If you submit new examples, try to make the example only 
do a single thing. Of course this is nearly impossible, so when you need to add additional complexity, just
reference other examples.

Each of the examples should begin with "helloworld_" This will
help group the examples together on the user's computer


License and credits

Arduino IDE is developed and maintained by the Arduino team. The IDE is licensed under GPL.
https://github.com/esp8266/Arduino

ESP8266 core includes an xtensa gcc toolchain, which is also under GPL.

Esptool written by Christian Klippel is licensed under GPLv2, currently maintained by Ivan Grokhotkov: https://github.com/igrr/esptool-ck.

Espressif SDK included in this build is under Espressif MIT License.

ESP8266 core files are licensed under LGPL.

SPI Flash File System (SPIFFS) written by Peter Andersson is used in this project. It is distributed under MIT license.
