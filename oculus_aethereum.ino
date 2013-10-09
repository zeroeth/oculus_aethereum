#include <Adafruit_NeoPixel.h>

#include "segment_models.h"
#include "segment_views.h"


// Initialize

#define PIN 4
#define LED_COUNT 32

#define  LEFT_EYE_START 0
#define RIGHT_EYE_START 16
#define LEDS_PER_EYE 16

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel (LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);


// Create all your movers and shakers here!

Wobbler wobble0 = Wobbler (/* position */ 0.5,
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

Pulsar pulsar2 =   Pulsar (/* position */ 0.0,
                           /* width    */ 4,
                           /* color    */ led_strip.Color (5, 5, 0));


// Theme 2

Grower grower1 =   Grower (/* position */ 0.0,
                           /* width    */ 16,
                           /* color    */ led_strip.Color (5, 0, 5));

Grower grower2 =   Grower (/* position */ 0.0,
                           /* width    */ 8,
                           /* color    */ led_strip.Color (0, 1, 5));

Circler circle2 = Circler (/* position */ 0.5,
                           /* width    */ 10,
                           /* color    */ led_strip.Color (1, 4, 0));

Wobbler wobble2 = Wobbler (/* position */ 0.5,
                           /* width    */ 2,
                           /* color    */ led_strip.Color (5, 5, 0));

// Theme 3

Wobbler  long_wobbler = Wobbler(0.0, 24, led_strip.Color (0, 5, 5));
Wobbler short_wobbler = Wobbler(0.5,  4, led_strip.Color (5, 0, 5));
Wobbler  spot_wobbler = Wobbler(0.1,  1, led_strip.Color (5, 0, 1));


// Theme X

Wobbler wobble3 = Wobbler (/* position */ 0.0,
                           /* width    */ 1,
                           /* color    */ led_strip.Color (0, 5, 1));

Wobbler wobble4 = Wobbler (/* position */ 0.25,
                           /* width    */ 1,
                           /* color    */ led_strip.Color (0, 5, 1));

Wobbler wobble5 = Wobbler (/* position */ 0.5,
                           /* width    */ 1,
                           /* color    */ led_strip.Color (0, 5, 1));

Wobbler wobble6 = Wobbler (/* position */ 0.75,
                           /* width    */ 1,
                           /* color    */ led_strip.Color (0, 5, 1));

Circler circle3 = Circler (/* position */ 0.0,
                           /* width    */ 2,
                           /* color    */ led_strip.Color (5, 1, 0));

Circler circle4 = Circler (/* position */ 0.33,
                           /* width    */ 2,
                           /* color    */ led_strip.Color (5, 1, 0));

Circler circle5 = Circler (/* position */ 0.66,
                           /* width    */ 2,
                           /* color    */ led_strip.Color (5, 1, 0));

// Create containers for sections of your LED strands/circles.

StripView   left_eye = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE);
StripView  right_eye = StripView (led_strip, RIGHT_EYE_START, LEDS_PER_EYE);

StripView  both_eyes = StripView (led_strip,  LEFT_EYE_START, LEDS_PER_EYE * 2);


void setup ()
{
  // Aways give your project a safe boot delay so you can re-upload code when:
  //   - it uses too much current when your LEDs are too bright
  //   - the serial doesn't respond because of some timing issue
  delay(5000);

  led_strip.begin ();

   // Add spots to each section

   // Theme 1
   /*
    wobble0.speed = 0.5;
    left_eye.add (wobble1);
    left_eye.add (wobble0);

   circle1.speed = -1.0;
   right_eye.add (circle1);
   pulsar1.speed = 2.0;
   right_eye.add (pulsar1);
   right_eye.add (pulsar2);
   */

   // Theme 2
   /*
    left_eye.add (grower1);
    left_eye.add (grower2);
   right_eye.add (circle2);
   right_eye.add (wobble2);
   */

   // Theme 3
   /*
   both_eyes.add ( long_wobbler);
   both_eyes.add (short_wobbler);
   both_eyes.add ( spot_wobbler);
   */

   // Theme X
   wobble3.speed = 0.4;
   wobble4.speed = 0.4;
   wobble5.speed = 0.4;
   wobble6.speed = 0.4;
    left_eye.add (wobble3);
    left_eye.add (wobble4);
    left_eye.add (wobble5);
    left_eye.add (wobble6);
   circle3.speed = 0.6;
   circle4.speed = 0.6;
   circle5.speed = 0.6;
   right_eye.add (circle3);
   right_eye.add (circle4);
   right_eye.add (circle5);
}



// Main Loop

void loop ()
{
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
