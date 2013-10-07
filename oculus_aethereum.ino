#include <Adafruit_NeoPixel.h>

#include "segment_models.h"
#include "segment_views.h"


/* TODO
   concept of rendering to individual or both eyes with wrapping
   contain items in a list (or multiple lists.. one for each or both eyes)
   eye 'render' code which does blend, or average or subtract/multiple
   render black masks as a color

   sub pixel rendering..
   'clear' fading.
   width
   speed

   wobbler
   pulser (frequency of human breath.. like macbook)
*/


/* Initialize */

#define PIN 4
#define LED_COUNT 32

#define  LEFT_EYE_START 0
#define RIGHT_EYE_START 16
#define LEDS_PER_EYE 16

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel (LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

Spot spot1 =         Spot (/* position */ 0.5,
                           /* width    */ 2,
                           /* color    */ led_strip.Color (5, 0, 5));

Circler circle1 = Circler (/* position */ 0.0,
                           /* width    */ 6,
                           /* color    */ led_strip.Color (0, 5, 5));


Wobbler wobble1 = Wobbler (/* position */ 0.0,
                           /* width    */ 4,
                           /* color    */ led_strip.Color (0, 0, 5));

Pulsar pulsar1 =   Pulsar (/* position */ 0.5,
                           /* width    */ 1,
                           /* color    */ led_strip.Color (5, 5, 0));

StripView  left_eye = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE);
StripView right_eye = StripView (led_strip, RIGHT_EYE_START, LEDS_PER_EYE);


void setup ()
{
  /* Aways give your project a safe boot delay so you can re-upload code when:
     - it uses too much current when your LEDs are too bright
     - the serial doesn't respond because of some timing issue */
  delay(5000);

  led_strip.begin ();

   left_eye.add (wobble1);
   left_eye.add (spot1  );

  right_eye.add (circle1);
  right_eye.add (pulsar1);
}



/* Main Loop */

void loop ()
{
  clear();

   left_eye.update ();
  right_eye.update ();

   left_eye.draw ();
  right_eye.draw ();

  led_strip.show ();
}


/* TODO move this into a goggle thing, so that clears can also be fades or whatever */
void clear ()
{
  for(uint16_t i=0; i< led_strip.numPixels (); i++) {
      led_strip.setPixelColor (i, led_strip.Color(0,0,0));
  }
}
