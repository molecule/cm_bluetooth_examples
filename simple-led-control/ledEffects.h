uint32_t pixelColors[NUM_LEDS];
float fadeRate = 0.96;
int brightness = 90;
int delayVal = 50;
uint32_t hot_pink      = strip.Color(48, 0, 24);

static void chase() {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , hot_pink); // Draw new pixel
      strip.setPixelColor(i-1, 0); // Erase pixel a few steps back
      strip.setBrightness(brightness); strip.show();
      delay(delayVal);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}


// An equally distributed rainbow. Is there any other kind?
void rainbowCycle() {
  uint8_t wait = 5;
  uint16_t i, j;

  for(j=0; j<256*2; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.setBrightness(70); strip.show();
    delay(wait);
  }
}

// A tasteful sparkle of blue.
void blue_sparkles() {
  for(int j=0; j<1000; j++) {
   if (random(8) == 1) {
      uint16_t i = random(NUM_LEDS);
      if (pixelColors[i] < 1) {
        pixelColors[i] = random(256);
      }
    }
    
    for(int i = 0; i < NUM_LEDS; i++) {
      if (pixelColors[i] > 1) {
        strip.setPixelColor(i, pixelColors[i]);
        
        if (pixelColors[i] > i) {
          pixelColors[i] = pixelColors[i] * fadeRate;
          //pixelColors[i] = pixelColors[i] >> 1;
        } else {
          pixelColors[i] = 0;
        }
        
      } else {
        strip.setPixelColor(i, 0, 0, 0);
      }
    }
    strip.setBrightness(brightness); strip.show();
    delay(5);
  }
}
