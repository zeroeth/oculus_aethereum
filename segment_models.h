#include "Arduino.h"

#ifndef SEGMENT_MODELS
#define SEGMENT_MODELS

class Spot {
 public:
  double   position;
  uint8_t  width;
  uint32_t color;

  /* Constructor */
  Spot (double, uint8_t, uint32_t);

  /* Methods */
  void update ();
};

#endif
