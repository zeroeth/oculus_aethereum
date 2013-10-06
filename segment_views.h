#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#include "segment_models.h"

#ifndef SEGMENT_VIEWS
#define SEGMENT_VIEWS

class StripView {
 public:

  /* Constructor */
  StripView (Adafruit_NeoPixel&, int, int);

  /* Methods */
  void add (Spot&);
  void update ();
  void draw   ();
};

#endif
