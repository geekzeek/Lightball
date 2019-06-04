//*******************PALETTES******************//
#define N_PALETTES 7

CRGB rColor(uint8_t h, uint8_t v){
  if(h < 96) return ColorFromPalette(HeatColors_p, map(h, 0, 95, 64, 160), v, LINEARBLEND);
  else return CHSV(h, random8(192, 255), v);
}

CRGBPalette16 randomPalette(){
  CRGBPalette16 palette;
  if(random8() < 16){
    int index = random(N_PALETTES);
    if(index == 0){
      palette = RainbowColors_p;
    }
    if(index == 1){
      palette = PartyColors_p;
    }
    if(index == 2){
      palette = CRGBPalette16(CRGB::Red, CRGB::Red, CRGB::Black, CRGB::Black,
                                CRGB::Black, CRGB::Blue, CRGB::Blue, CRGB::Black,
                                CRGB::Black, CRGB::Black, CRGB::Green, CRGB::Green,
                                CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);
    }
    if(index == 3){
      palette = CRGBPalette16(CRGB::Blue, CRGB::Blue, CRGB::White, CRGB::Blue,
                                CRGB::Blue, CRGB::Red, CRGB::Red, CRGB::White,
                                CRGB::Red, CRGB::Red, CRGB::White, CRGB::Red,
                                CRGB::Red, CRGB::White, CRGB::Black, CRGB::Black);
    }
    if(index == 4){
      CRGB pr = CHSV(205, 255, 255);
      CRGB go = CHSV( 30, 255, 255);
      CRGB bl = CHSV(  0,   0,   0); 
      palette = CRGBPalette16(pr, pr, pr, pr, bl, go, go, go, bl, pr, pr, pr, pr, bl, bl, bl);
    }
    if(index == 5){
      CRGB li = CHSV( 81, 255, 255);
      CRGB nv = CHSV(153, 155, 200);
      CRGB gr = CHSV(  0,   0, 145);
      CRGB wh = CHSV(  0,   0, 255);
      CRGB bl = CHSV(  0,   0,   0); 
      palette = CRGBPalette16(li, li, li, nv, nv, nv, nv, nv, li, li, li, bl, bl, bl, wh, wh);
    }
    if(index == 6){
      CRGB wh = CHSV(37, 80, 255);
      CRGB br = CHSV(33, 192, 192);
      CRGB bl = CHSV(  0,   0,   0); 
      palette =CRGBPalette16(br, bl, wh, wh, bl, wh, br, br, bl, br, br, br, br, bl, bl, bl);
    }
  } else {
    //**************************GENERATE RANDOM COLOR PALETTE*******************************//
    uint8_t PRESET = random8(5);
    if(PRESET == 0){
      // Dots
      uint8_t hue = random8();
      palette[0] = rColor(hue, 192);
      palette[1] = rColor(hue, 255);
      palette[2] = rColor(hue, 192);
      palette[3] = CRGB::Black;
      palette[4] = CRGB::Black;
      hue += random8(32, 112);
      palette[5] = rColor(hue, 192);
      palette[6] = rColor(hue, 255);
      palette[7] = rColor(hue, 192);
      palette[8] = CRGB::Black;
      palette[9] = CRGB::Black;
      hue += random8(32, 112);
      palette[10]= rColor(hue, 192);
      palette[11]= rColor(hue, 255);
      palette[12]= rColor(hue, 192);
      palette[13]= CRGB::Black;
      palette[14]= CRGB::Black;
      palette[15]= CRGB::Black;
    }

    if(PRESET == 1){
      //Gradient white center ribbon with sparkle
      uint8_t hue = random8();
      palette[0] = CRGB::Black;
      palette[1] = CHSV(hue, 255, 192);
      palette[2] = CRGB::Black;
      palette[3] = CHSV(hue, 255, 96);
      palette[4] = CHSV(hue, 255, 128);
      palette[5] = CHSV(hue, 255, 160);
      palette[6] = CHSV(hue, 255, 192);
      palette[7] = CHSV(hue, 255, 224);
      palette[8] = CHSV(hue, 255, 255);
      palette[9] = CHSV(hue, 255, 255);
      palette[10]= CHSV(hue + 32, 255, 255);
      palette[11]= CRGB::White;
      palette[12]= CHSV(hue + 32, 255, 255);
      palette[13]= CHSV(hue, 255, 255);
      palette[14]= CHSV(hue, 255, 192);
      palette[15]= CRGB::Black;
    }
    if(PRESET == 2){
      // Hue gradient into white
      uint8_t hue = random8();
      uint8_t target = 64 + random(128);
      palette[0] = CRGB::Black;
      palette[1] = CHSV(hue, 255, 48);
      palette[2] = CHSV(hue, 255, 96);
      palette[3] = CHSV(hue, 255, 144);
      palette[4] = CHSV(hue, 255, 192);
      palette[5] = CHSV(hue + target * 1/10, 255, 255);
      palette[6] = CHSV(hue + target * 2/10, 255, 255);
      palette[7] = CHSV(hue + target * 3/10, 255, 225);
      palette[8] = CHSV(hue + target * 4/10, 255, 255);
      palette[9] = CHSV(hue + target * 5/10, 255, 255);
      palette[10]= CHSV(hue + target * 6/10, 255, 255);
      palette[11]= CHSV(hue + target * 7/10, 255, 255);
      palette[12]= CHSV(hue + target * 8/10, 192, 255);
      palette[13]= CHSV(hue + target * 9/10, 128, 255);
      palette[14]= CHSV(hue + target, 64, 255);
      palette[15]= CRGB::White;
    }
    
    if(PRESET == 3){
      uint8_t h0 = random8();
      palette[0] = CHSV(h0 + 32, 255, 255);
      palette[1] = CHSV(h0, 255, 255);
      palette[2] = CHSV(h0, 255, 192);
      palette[3] = CRGB::Black;
      palette[4] = CRGB::Black;
      palette[5] = CRGB::Black;
      palette[6] = CRGB::Black;
      palette[7] = CRGB::Black;
      palette[8] = CRGB::Black;
      palette[9] = CRGB::Black;
      palette[10]= CRGB::Black;
      palette[11]= CRGB::Black;
      palette[12]= CRGB::Black;
      palette[13]= CRGB::Black;
      palette[14]= CHSV(h0, 255, 192);
      palette[15]= CHSV(h0, 255, 255);
      
   }

    if(PRESET == 4){
      uint8_t h0 = random8();
      uint8_t offset = random8(8, 24);
      palette[0] = CHSV(h0 + offset * 0, 255, 255);
      palette[1] = CHSV(h0 + offset * 1, 255, 255);
      palette[2] = CHSV(h0 + offset * 2, 255, 255);
      palette[3] = CHSV(h0 + offset * 3, 255, 255);
      palette[4] = CHSV(h0 + offset * 4, 255, 255);
      palette[5] = CHSV(h0 + offset * 5, 255, 255);
      palette[6] = CHSV(h0 + offset * 6, 255, 255);
      palette[7] = CHSV(h0 + offset * 7, 255, 255);
      palette[8] = CHSV(h0 + offset * 8, 255, 255);
      palette[9] = CHSV(h0 + offset * 7, 255, 255);
      palette[10]= CHSV(h0 + offset * 6, 255, 255);
      palette[11]= CHSV(h0 + offset * 5, 255, 255);
      palette[12]= CHSV(h0 + offset * 4, 255, 255);
      palette[13]= CHSV(h0 + offset * 3, 255, 255);
      palette[14]= CHSV(h0 + offset * 2, 255, 255);
      palette[15]= CHSV(h0 + offset * 1, 255, 255);
    }
    
  }
  return palette;
}
