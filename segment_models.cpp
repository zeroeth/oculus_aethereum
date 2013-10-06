#include "segment_models.h"

Spot::Spot (double n_position, uint8_t n_width, uint32_t n_color):
  position (n_position),
  width (n_width),
  color (n_color) /* Initializer list */
{
}


void Spot::update ()
{
  /* TODO move this to a circler */
  position = millis() % 1000;

  position *= 0.001;
}
