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
    uint32_t start_color = strip.getPixelColor (i);
    uint8_t r,g,b;

    r = (uint8_t)(start_color >> 16),
    g = (uint8_t)(start_color >>  8),
    b = (uint8_t)(start_color >>  0);

    // Dim brightness FIXME fails to gracefully fade dim colors (because it runs a lot per second)
    uint32_t color = strip.Color (r * 0.9, g * 0.9, b * 0.9);

    strip.setPixelColor (i, color);
    //strip.setPixelColor (i, strip.Color(0,0,0));
  }
}


// Draw a color into the strip

void StripView::draw_at (uint8_t position, uint32_t color)
{
  strip.setPixelColor (position, color);
}


// Add color into the strip

void StripView::add_at (uint8_t position, uint32_t color)
{
  uint32_t added_colors = add_colors (color, strip.getPixelColor (position));
  strip.setPixelColor (position, added_colors);
}


// Blend two colors together

uint32_t StripView::add_colors (uint32_t color1, uint32_t color2)
{
  uint8_t r1,g1,b1;
  uint8_t r2,g2,b2;
  uint8_t r3,g3,b3;

  r1 = (uint8_t)(color1 >> 16),
  g1 = (uint8_t)(color1 >>  8),
  b1 = (uint8_t)(color1 >>  0);

  r2 = (uint8_t)(color2 >> 16),
  g2 = (uint8_t)(color2 >>  8),
  b2 = (uint8_t)(color2 >>  0);


  return strip.Color (constrain (r1+r2, 0, 255), constrain (g1+g2, 0, 255), constrain (b1+b2, 0, 255));
}

