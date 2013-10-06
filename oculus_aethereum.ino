#include <Adafruit_NeoPixel.h>

#include "segment_models.h"
#include "segment_views.h"


/* TODO
   concept of rendering to individual or both eyes with wrapping
   contain items in a list (or multiple lists.. one for each or both eyes)
   eye 'render' code which does blend, or average or subtract/multiple
   render black masks as a color

   spot
   wobbler
   circler
   pulser
*/


/* Initialize */

#define PIN 4
#define LED_COUNT 32

#define  LEFT_EYE_START 0
#define RIGHT_EYE_START 16
#define LEDS_PER_EYE 16

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel (LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

Spot spot = Spot (/* position */ 0.5,
                  /* width    */ 3,
                  /* color    */ led_strip.Color (5, 0, 0));

StripView  left_eye = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE);
StripView right_eye = StripView (led_strip, RIGHT_EYE_START, LEDS_PER_EYE);


void setup ()
{
  left_eye.add (spot);
}



/* Main Loop */

void loop ()
{
   left_eye.update ();
  right_eye.update ();

   left_eye.draw ();
  right_eye.draw ();
}
