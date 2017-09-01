uint8_t INCREMENT = 1;
int EPISODETIME = 0;
int STARTTIME = 0;
int BRIGHTNESS = 0;
int i, j;

void showFrame(int FRAMERATE){
  BRIGHTNESS = analogRead(0)/4;
  if(EPISODETIME < BRIGHTNESS) FastLED.setBrightness(EPISODETIME);
  else if(STARTTIME - EPISODETIME < BRIGHTNESS) FastLED.setBrightness(STARTTIME - EPISODETIME);
  else FastLED.setBrightness(BRIGHTNESS);
  
  TIME += INCREMENT;
  EPISODETIME--;
  delay(1000/FRAMERATE);
  FastLED.show();
}


void barberPole(){
  EPISODETIME = STARTTIME = random(512, 1024);
  INCREMENT = random(1, 4);
  float SCALE = random(600, 2600)/100.0;
  if (random(2) < 1) INCREMENT *= -1;
  cPalette = randomPalette();


  while(EPISODETIME > 0){
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < LENGTH; j++){
        leds[i][j] = ColorFromPalette(cPalette, TIME + j*255/SCALE + i*255/WIDTH,  255, LINEARBLEND);
      }
    }
    showFrame(60);
  }
}

void vortexPole(){
  EPISODETIME = STARTTIME = random(512, 1024);
  INCREMENT = random(1, 4);
  int SCALE = random(900, 2600)/100.0;
  if (random(2) < 1) INCREMENT *= -1;
  cPalette = randomPalette();

  while(EPISODETIME > 0){
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < LENGTH; j++){
        leds[i][j] = ColorFromPalette(cPalette, TIME + j*255/SCALE, 255, LINEARBLEND);
      }
    }
    showFrame(60);
  }
}





