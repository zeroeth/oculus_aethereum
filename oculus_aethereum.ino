#include <Adafruit_NeoPixel.h>

#include "segment_models.h"
#include "segment_views.h"
#include "themes.h"


// Initialize

#define PIN 4
#define LED_COUNT 32

#define  LEFT_EYE_START 0
#define RIGHT_EYE_START 16
#define LEDS_PER_EYE 16

#define THEME_SWITCH_DELAY 10000 // Milliseconds

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel (LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);


// Create containers for sections of your LED strands/circles.

StripView   left_eye = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE);
StripView  right_eye = StripView (led_strip, RIGHT_EYE_START, LEDS_PER_EYE);

StripView  both_eyes = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE * 2);

void setup ()
{
  // Aways give your project a safe boot delay so you can re-upload code when:
  //   - it uses too much current when your LEDs are too bright
  //   - the serial doesn't respond because of some timing issue

  delay(3000);

  led_strip.begin ();
}



// Main Loop

void loop ()
{
  // Switch themes every {x} seconds
  Theme::switch_every (THEME_SWITCH_DELAY);

   left_eye.clear ();
  right_eye.clear ();
  both_eyes.clear ();

  // Update the spots
   left_eye.update ();
  right_eye.update ();
  both_eyes.update ();

  // Draw the spots.
   left_eye.draw ();
  right_eye.draw ();
  both_eyes.draw ();

  led_strip.show ();
}
