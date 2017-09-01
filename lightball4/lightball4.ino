#include <FastLED.h>
#include <EEPROM.h>

//********************LEDS********************//
#define WIDTH 5
#define LENGTH 13

uint8_t TIME = 0;

CRGB leds[WIDTH][LENGTH];

void incrementRandomSeed(uint8_t increment){
  int seed = word(EEPROM.read(0), EEPROM.read(1));
  seed += increment;
  EEPROM.write(0, highByte(seed));
  EEPROM.write(1, lowByte(seed));
}

void setup() {
  FastLED.addLeds<NEOPIXEL, 3>(leds[0], 13);
  FastLED.addLeds<NEOPIXEL, 5>(leds[1], 13);
  FastLED.addLeds<NEOPIXEL, 6>(leds[2], 13);
  FastLED.addLeds<NEOPIXEL, 9>(leds[3], 13);
  FastLED.addLeds<NEOPIXEL, 10>(leds[4], 13);
  FastLED.setBrightness(0);
  
  randomSeed(word(EEPROM.read(0), EEPROM.read(1)));

  setupPalettes();

  Serial.begin(9600);
  Serial.println(word(EEPROM.read(0), EEPROM.read(1)));
  Serial.end();
  
}

void loop() {
  if(analogRead(0) > 1){
    switch(random(2)){
      case 0:
        barberPole();
        break;
      case 1:
        vortexPole();
        break;
    }
  }
  else{
    incrementRandomSeed(TIME);
  }
  delay(1000);
}
