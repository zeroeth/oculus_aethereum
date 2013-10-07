#include "segment_models.h"



/*** Spot Methods *********************************************/

// Base Spot Constructor

Spot::Spot (double n_position, uint8_t n_width, uint32_t n_color):
  position (n_position),
  width (n_width),
  color (n_color) /* Initializer list */
{
}


// Virtual update to be implemented by subclasses

void Spot::update () { }



/*** Circler Methods ******************************************/

// Circler Constructor

Circler::Circler (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
}


// Scale from 0 to 1 once a second

void Circler::update ()
{
  position = millis() % 1000;
  position *= 0.001;
}



/*** Wobbler Methods ******************************************/

// Wobbler Constructor

Wobbler::Wobbler (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
}


// Scale from 0 to 6.28 every second

void Wobbler::update ()
{
  position = millis() % 1000;
  position *= 0.00628;

  // Scale -1/1 to 0/1

  position = (sin(position) + 1) * 0.5;
}



/*** Pulsar Methods ******************************************/

// Pulsar Constructor

Pulsar::Pulsar (double n_position, uint8_t n_width, uint32_t n_color):
  Spot(n_position, n_width, n_color) /* Base Class Constructor */
{
}

void Pulsar::update ()
{
  double value = millis() % 1000;
  value *= 0.00628;

  // Scale -1/1 to 0/1
  value = (sin(value) + 1) * 0.5;

  // Brightness 0 to 5
  value *= 10;

  /* TODO extract original colors, also maybe store basic color primitives? rgb or hsl on the models */
  color = led_strip.Color (value, value, 0);
}
