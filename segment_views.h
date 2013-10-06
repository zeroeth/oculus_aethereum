#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#include "segment_models.h"

#ifndef SEGMENT_VIEWS
#define SEGMENT_VIEWS

class StripView {
 public:
  Adafruit_NeoPixel &strip;
  uint8_t starting_led;
  uint8_t length;

  /* Constructor */
  StripView (Adafruit_NeoPixel&, uint8_t, uint8_t);

  /* Methods */
  void add (Spot&);
  void update ();
  void draw   ();
};

#endif
