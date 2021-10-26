void Sparkle(int red, int green, int blue, int delayDuration) {
  int pixel = random(NUM_LEDS);
  leds[pixel].setRGB(red, green, blue);
  FastLED.show();
  delay(delayDuration);
  leds[pixel].setRGB(0, 0, 0);
}

void electromagneticSpectrum(int transitionSpeed) {
  switch(colorTime) {
    case 1:
      greenColor += transitionSpeed;
      blueColor -= transitionSpeed;
      if (greenColor >= 255 or blueColor <= 0) {
        greenColor = 255;
        blueColor = 0;
        colorTime = 2;
      }
      break;
    case 2:
      redColor += transitionSpeed;
      greenColor -= transitionSpeed;
      if (redColor >= 255 or greenColor <= 0) {
        redColor = 255;
        greenColor = 0;
        colorTime = 3;
      }
      break;
    case 3:
      redColor -= transitionSpeed;
      blueColor += transitionSpeed;
      if (redColor <= 0 or blueColor >= 255) {
        redColor = 0;
        blueColor = 255;
        colorTime = 1;
      }
      break;
  }
}
