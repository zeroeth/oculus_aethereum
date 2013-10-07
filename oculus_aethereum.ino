#include <Adafruit_NeoPixel.h>

#include "segment_models.h"
#include "segment_views.h"


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

Wobbler wobble1 = Wobbler (/* position */ 0.0,
                           /* width    */ 4,
                           /* color    */ led_strip.Color (0, 0, 5));

Circler circle1 = Circler (/* position */ 0.0,
                           /* width    */ 6,
                           /* color    */ led_strip.Color (0, 5, 5));

Pulsar pulsar1 =   Pulsar (/* position */ 0.5,
                           /* width    */ 4,
                           /* color    */ led_strip.Color (5, 5, 0));

StripView   left_eye = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE);
StripView  right_eye = StripView (led_strip, RIGHT_EYE_START, LEDS_PER_EYE);

StripView  both_eyes = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE * 2);


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
   left_eye.clear ();
  right_eye.clear ();

   left_eye.update ();
  right_eye.update ();

   left_eye.draw ();
  right_eye.draw ();

  led_strip.show ();
}
