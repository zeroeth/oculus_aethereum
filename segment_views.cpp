#include "segment_views.h"


StripView::StripView (Adafruit_NeoPixel& n_strip, uint8_t n_starting_led, uint8_t n_length):
  strip (n_strip),
  starting_led (n_starting_led),
  length (n_length),
  spot_count (0) /* Initializer list */
{
}


void StripView::add (Spot &spot)
{
  spots[spot_count] = &spot;
  spot_count++;
}


void StripView::update ()
{
  for(int i = 0; i < spot_count; i++)
  {
    spots[i]->update ();
  }
}


void StripView::draw ()
{
  /* Draw each spot. TODO figure out where strip view and spot view separate for drawing logic.. does spot view create the dots and colors and then strip over lays those pixels into its buffer (additive or whatever) */

  for(int i = 0; i < spot_count; i++)
  {
    spots[i]->update ();

    strip.setPixelColor (int(spots[i]->position * length) + starting_led, spots[i]->color);
  }
}

