#include <FastLED.h>
#include <EEPROM.h>

//********************LEDS********************//
#define WIDTH 3
#define LENGTH 10

uint8_t TIME = 0;

CRGB leds[WIDTH][LENGTH];

void incrementRandomSeed(uint8_t increment){
  int seed = word(EEPROM.read(0), EEPROM.read(1));
  seed += increment;
  EEPROM.write(0, highByte(seed));
  EEPROM.write(1, lowByte(seed));
}

void setup() {
  FastLED.addLeds<NEOPIXEL, 3>(leds[0], LENGTH);
  FastLED.addLeds<NEOPIXEL, 6>(leds[1], LENGTH);
  FastLED.addLeds<NEOPIXEL, 5>(leds[2], LENGTH);
  // FastLED.addLeds<NEOPIXEL, 9>(leds[3], 13);
  // FastLED.addLeds<NEOPIXEL, 10>(leds[4], 13);
  FastLED.setBrightness(0);
  
  randomSeed(word(EEPROM.read(0), EEPROM.read(1)));
  
  Serial.begin(9600);
  Serial.println(word(EEPROM.read(0), EEPROM.read(1)));
  Serial.end();
}

void loop() {
  switch(1){
    case 0:
      barberPole();
      break;
    case 1:
      vortexPole();
      break;
  }

  incrementRandomSeed(1);

  int i, j;
  for(i = 0; i < WIDTH; i++){
    for(j = 0; j < LENGTH; j++){
      leds[i][j] = CRGB::Black;
    }
  }
  FastLED.show();

  delay(map(getEntropy(), 1, 1024, 1000, 50));
}
