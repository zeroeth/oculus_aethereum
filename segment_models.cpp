#include "segment_models.h"



/*** Spot Methods *********************************************/

// Base Spot Constructor

Spot::Spot (double n_position, uint8_t n_width, uint32_t n_color):
  position  (n_position),
  width     (n_width),
  color     (n_color), /* Initializer list */
  speed     (1.0),
  amplitude (1.0),
  offset (0)
{
}



// Virtual update to be implemented by subclasses

void Spot::update () { }


// Return a 0.0 to 1.0 scaled over {speed} + {offset} seconds

double Spot::percent ()
{
  return (int((millis() * speed) + (offset*1000)) % 1000) * 0.001;
}


/*** Circler Methods ******************************************/

// Circler Constructor

Circler::Circler (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
  start_position = position;
}


// Scale from 0 to 1 once a second

void Circler::update ()
{
  position = percent () + start_position;
}



/*** Wobbler Methods ******************************************/

// Wobbler Constructor

Wobbler::Wobbler (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
  start_position = position;
}



void Wobbler::update ()
{
  // Scale from 0 to 6.28 every second
  position = percent () * M_PI * 2;

  // Scale -1/1 to 0/1
  position  = (sin(position) + 1) * 0.5;
  position += start_position;
}



/*** Pulsar Methods ******************************************/

// Pulsar Constructor

Pulsar::Pulsar (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
  start_color = color;
}

void Pulsar::update ()
{
  double value = percent () * M_PI * 2;

  // Scale -1/1 to 0/1
  value = (sin(value) + 1) * 0.5;

  // Extract original r g b
  uint8_t r,g,b;

  r = (uint8_t)(start_color >> 16),
  g = (uint8_t)(start_color >>  8),
  b = (uint8_t)(start_color >>  0);

  // Dim brightness
  color = led_strip.Color (r * value, g * value, b * value);
}



/*** Grower Methods ******************************************/

// Grower Constructor

Grower::Grower (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
  start_width = width;
}

void Grower::update ()
{
  double value = percent () * M_PI * 2;

  // Scale -1/1 to 0/1
  value = (sin(value) + 1) * 0.5;

  // Width 0 to 10
  width = value * start_width;

}
