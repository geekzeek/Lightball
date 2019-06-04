int INCREMENT = 1;
int DIRECTION = 1;
int EPISODETIME = 0;
int STARTTIME = 0;
int BRIGHTNESS = 0;
int ENTROPY = 0;
int FRAMETIME = 0;
int FADETIME = 0;
float SCALE;
int i, j;

int getEntropy(){
  return ENTROPY;
}

void showFrame(){
  BRIGHTNESS = analogRead(1)/8;
  ENTROPY = 1024 - analogRead(0);

  // Hack to allow faster movement
  // INCREMENT = pow(2, ENTROPY/256);
  // FRAMETIME = map(ENTROPY/INCREMENT, 1, 1024, 60, 1);

  if(ENTROPY < 256){
    INCREMENT = 1 * DIRECTION;
    FRAMETIME = map(ENTROPY, 0, 256, 30, 1);
  } else if (ENTROPY < 512){
    INCREMENT = 2 * DIRECTION;
    FRAMETIME = map(ENTROPY, 256, 512, 10, 1);
  } else if (ENTROPY < 768){
    INCREMENT = 3 * DIRECTION;
    FRAMETIME = map(ENTROPY, 512, 768, 10, 1);
  } else {
    INCREMENT = 4 * DIRECTION;
    FRAMETIME = map(ENTROPY, 768, 1024, 10, 1);
  }

  FADETIME = EPISODETIME/4;
  if(FADETIME < BRIGHTNESS) FastLED.setBrightness(FADETIME);
  else if((STARTTIME - EPISODETIME)/4 < BRIGHTNESS) FastLED.setBrightness((STARTTIME - EPISODETIME)/4);
  else FastLED.setBrightness(BRIGHTNESS);
  
  TIME += INCREMENT;
  EPISODETIME -= FRAMETIME;
  delay(FRAMETIME);
  FastLED.show();
}

// void showFrame(){
//   BRIGHTNESS = analogRead(1)/8;
//   ENTROPY = 1024 - analogRead(0);

//   // Hack to allow faster movement
//   if(ENTROPY < 256){
//     INCREMENT = 1;
//     FRAMETIME = map(ENTROPY, 0, 256, 100, 1);
//   } else if (ENTROPY < 512){
//     INCREMENT = 2;
//     FRAMETIME = map(ENTROPY, 256, 512, 10, 1);
//   } else if (ENTROPY < 768){
//     INCREMENT = 3;
//     FRAMETIME = map(ENTROPY, 512, 768, 10, 1);
//   } else {
//     INCREMENT = 4;
//     FRAMETIME = map(ENTROPY, 768, 1024, 10, 1);
//   }
//   // int TimeToFinish = EPISODETIME - CURRENTTIME;
//   // int TimeSinceStart = CURRENTTIME - STARTTIME;
//   // if(TimeSinceStart < 1024){
//   //   if(TimeSinceStart/4 < BRIGHTNESS){
//   //     FastLED.setBrightness(TimeSinceStart/4);
//   //   }
//   // }
//   // else if(TimeToFinish < 1024){
//   //   if(TimeToFinish/4 < BRIGHTNESS){
//   //     FastLED.setBrightness(TimeToFinish/4);
//   //   }
//   // }

//   FastLED.setBrightness(BRIGHTNESS);
//   TIME += INCREMENT;
//   EPISODETIME--;
//   delay(FRAMETIME);
//   FastLED.show();
// }


void barberPole(){
  EPISODETIME = STARTTIME = random(10000, 10000);
  SCALE = random(700, 1500)/100.0;
  if (random(2) == 1) DIRECTION *= -1;
  CRGBPalette16 cPalette = randomPalette();

  while(EPISODETIME > 0){
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < LENGTH; j++){
        leds[i][j] = ColorFromPalette(cPalette, TIME + j*255/SCALE + i*255/WIDTH,  255, LINEARBLEND);
      }
    }
    showFrame();
  }
}

void vortexPole(){
  EPISODETIME = STARTTIME = random(10000, 10000);
  SCALE = random(700, 1500)/100.0;
  if (random(2) == 1) DIRECTION *= -1;
  CRGBPalette16 cPalette = randomPalette();

  while(EPISODETIME > 0){
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < LENGTH; j++){
        leds[i][j] = ColorFromPalette(cPalette, TIME + j*255/SCALE, 255, LINEARBLEND);
      }
    }
    showFrame();
  }
}





