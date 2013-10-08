#include "segment_models.h"



/*** Spot Methods *********************************************/

// Base Spot Constructor

Spot::Spot (double n_position, uint8_t n_width, uint32_t n_color):
  position (n_position),
  width    (n_width),
  color    (n_color), /* Initializer list */
  speed    (1.0),
  multiply (1.0)
{
}


// Virtual update to be implemented by subclasses

void Spot::update () { }


// Return a 0.0 to 1.0 scaled over (multiply) seconds

double Spot::percent ()
{
  return (int(millis()*speed) % 1000) * 0.001;
}


/*** Circler Methods ******************************************/

// Circler Constructor

Circler::Circler (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
}


// Scale from 0 to 1 once a second

void Circler::update ()
{
  position = percent ();
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
}

void Pulsar::update ()
{
  double value = percent () * M_PI * 2;

  // Scale -1/1 to 0/1
  value = (sin(value) + 1) * 0.5;

  // Brightness 0 to 5
  value *= 10;

  /* TODO extract original colors, also maybe store basic color primitives? rgb or hsl on the models */
  color = led_strip.Color (value, value, 0);
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
