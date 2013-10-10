#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#include "segment_models.h"

#ifndef SEGMENT_VIEWS
#define SEGMENT_VIEWS

// StripView takes care of rendering all of the spots and interpreting their positions from 0 to 1 into the strips length. This way the spot models don't know anything specific about how they will end up being shown in the view.

class StripView {
 public:

  // Variables
  Adafruit_NeoPixel &strip;
  uint8_t starting_led;
  uint8_t length;

  Spot *spots[10];
  uint8_t spot_count;


  // Constructor
  StripView (Adafruit_NeoPixel&, uint8_t, uint8_t);


  // Methods
  void add (Spot*);
  void update ();
  void draw   ();
  void clear  ();
  void draw_at (uint8_t, uint32_t);
  void  add_at (uint8_t, uint32_t);
  uint32_t add_colors (uint32_t, uint32_t);
  void unload_theme ();
};

#endif
