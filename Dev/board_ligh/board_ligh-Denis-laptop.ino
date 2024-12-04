#include <FastLED.h>

#define NUM_LEDS 98
#define DATA_PIN 13

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);

  FastLED.setBrightness(255);
}

void loop() {

  for (int i = 0; i < 14; i++) {
    leds[i] = CRGB(119, 196, 220);
    FastLED.show();
  }

  for (int i = 14; i < 28; i++) {
    leds[i] = CRGB(119, 6, 220);
    FastLED.show();
  }

  for (int i = 28; i < 42; i++) {
    leds[i] = CRGB(0, 69, 59);
    FastLED.show();
  }

  for (int i = 42; i < 56; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }

  for (int i = 56; i < 70; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }
}
