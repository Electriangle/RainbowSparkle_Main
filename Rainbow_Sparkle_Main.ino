#include "FastLED.h"

#define NUM_LEDS  150    // Enter the total number of LEDs on the strip
#define PIN       7      // The pin connected to Din to control the LEDs

CRGB leds[NUM_LEDS];

// Initialize variables
int redColor = 0;
int greenColor = 0;
int blueColor = 255;
int colorTime = 1;

void setup() {
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);    // Set power limit of LED strip to 5V, 1500mA
  FastLED.clear();                                    // Initialize all LEDs to "off"
}

void loop() {
  Sparkle(redColor, greenColor, blueColor, 0);        // Sparkle animation
  electromagneticSpectrum(20);                        // Cycle through RGB colors
}
