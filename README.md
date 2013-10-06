Oculus Aethereum
================

At last my time translocating side arm was complete. I moved a chest of drawers in my bedroom and fired at the blank wall where it once was and lept in. I ended up at the 1964 worlds fair. A curious affair filled with technology that seemed like magic to my eyes. That's when a man dressed in a slim black suit, the finest linens I had ever laid eyes on handed me a pair of goggles. Their ominous glow was not like anything from my time, or this one. The man grasped on to them for a brief moment and uttered "You must find her" and slowly faded from existence.


Instructions
------------

* Connect two Adafruit NeoPixel Rings together
* Set the pin you use in the code (Default is 4)
* Upload the code using Arduino's software.


Nerdy Notes
-----------

The style of this code is based on a `Model/View` pattern:

The models (another name for classes that deal with data only) take care updating their information, in this case, the wobble or position of rotation of a light segment. The model's don't need to know about how many leds there are in a circle.

The `Views` gather their respective `Models` and render them to the NeoPixel strands.

This code is object oriented and avoids using `pointers` for simplicity, read more about C++ to learn about `pointers` and `references`

The `#IFNDEF SOMETHING_HERE` lines you see in the header files solve an annoying situation in C/C++ where including a header in multiple places gives a warning that whatever is in it has been defined twice.
