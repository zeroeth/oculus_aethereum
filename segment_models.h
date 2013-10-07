#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#ifndef SEGMENT_MODELS
#define SEGMENT_MODELS

extern Adafruit_NeoPixel led_strip; /* FIXME temporary global */

class Spot {
 public:

  /* Variables */
  double   position;
  uint8_t  width;
  uint32_t color;

  /* Constructor */
  Spot (double, uint8_t, uint32_t);

  /* Methods */
  virtual void update ();
};



class Circler : public Spot {
 public:

  /* Constructor */
  Circler (double, uint8_t, uint32_t);

  /* Methods */
  void update ();
};



class Wobbler : public Spot {
 public:

  /* Constructor */
  Wobbler (double, uint8_t, uint32_t);

  /* Methods */
  void update ();
};



class Pulsar : public Spot {
 public:

  /* Constructor */
  Pulsar (double, uint8_t, uint32_t);

  /* Methods */
  void update ();
};

#endif
