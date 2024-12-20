/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 98

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 13
// #define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  // Uncomment/edit one of the following lines for your leds arrangement.
  // ## Clockless types ##
  // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  // FastLED.addLeds<SM16703, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1829, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1904, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS2903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<GS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA106, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<PL9823, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GE8822, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD1886, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD1886_8BIT, DATA_PIN, RGB>(leds, NUM_LEDS);
  // ## Clocked (SPI) types ##
  // FastLED.addLeds<LPD6803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical

  FastLED.setBrightness(255);
}

void loop() {

  //1
  for (int i = 0; i < 14; i++) {
    leds[i] = CRGB(119, 196, 220);
    FastLED.show();
    // delay(100);
  }

  //2
  for (int i = 14; i < 28; i++) {
    leds[i] = CRGB(0, 69, 59);
    FastLED.show();
    // delay(100);
  }

  //3
  for (int i = 28; i < 42; i++) {
    leds[i] = CRGB(0, 69, 59);
    // leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    // delay(100);
  }

  //4
  for (int i = 42; i < 56; i++) {
    leds[i] = CRGB(1, 54, 46);
    FastLED.show();
    // delay(100);
  }

  //5
  for (int i = 56; i < 70; i++) {
    // leds[i] = CRGB(0, 69, 59);
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    // delay(100);
  }
 
}


// void loop() {

//   //1
//   for (int i = 0; i < 14; i++) {
//     leds[i] = CRGB(197, 199, 220);
//     FastLED.show();
//     // delay(100);
//   }

//   //2
//   for (int i = 14; i < 28; i++) {
//     leds[i] = CRGB(197, 199, 220);
//     FastLED.show();
//     // delay(100);
//   }

//   //3
//   for (int i = 28; i < 42; i++) {
//     leds[i] = CRGB(200, 120, 224);
//     FastLED.show();
//     // delay(100);
//   }

//   //4
//   for (int i = 42; i < 56; i++) {
//     leds[i] = CRGB(200, 120, 224);
//     FastLED.show();
//     // delay(100);
//   }

//   //5
//   for (int i = 56; i < 70; i++) {
//     leds[i] = CRGB(202, 120, 227);
//     FastLED.show();
//     // delay(100);
//   }

//   //6
//   for (int i = 70; i < 84; i++) {
//     // FastLED.setBrightness(200);
//     leds[i] = CRGB(173, 98, 199);
//     FastLED.show();
//     // delay(100);
//   }

//   //7
//   for (int i = 84; i < 98; i++) {
//     // FastLED.setBrightness(100);
//     leds[i] = CRGB(142, 75, 156);
//     FastLED.show();
//     // delay(100);
//   }

  

 
// }
