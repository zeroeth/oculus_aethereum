#include "segment_views.h"


// StripView Constructor

StripView::StripView (Adafruit_NeoPixel& n_strip, uint8_t n_starting_led, uint8_t n_length):
  strip (n_strip),
  starting_led (n_starting_led),
  length (n_length),
  spot_count (0) /* Initializer list */
{
}


// Add spot to list of spots for this view

void StripView::add (Spot &spot)
{
  spots[spot_count] = &spot;
  spot_count++;
}


// Update all spots

void StripView::update ()
{
  for(int i = 0; i < spot_count; i++)
  {
    spots[i]->update ();
  }
}


void StripView::draw ()
{
  /* TODO figure out where strip view and spot view separate for drawing logic.. does spot view create the dots and colors and then strip over lays those pixels into its buffer (additive or whatever) */

  // Draw every spot
  for (uint8_t i = 0; i < spot_count; i++)
  {
    spots[i]->update ();

    // For width of the spot
    for (uint8_t w = 0; w < spots[i]->width; w++)
    {
      // Map position to strip
      uint8_t position = (int(spots[i]->position * length) + w) - spots[i]->width/2;

      // Wrap around the segment
      draw_at ((position % length) + starting_led, spots[i]->color);
    }
  }
}


// Clear strip

void StripView::clear ()
{
  for(uint8_t i = starting_led; i < (starting_led+length); i++)
  {
     strip.setPixelColor (i, strip.Color(0,0,0));
  }
}


// Draw a color into the strip

void StripView::draw_at (uint8_t position, uint32_t color)
{
  strip.setPixelColor (position, color);
}
