> At last my time trans-location side arm was complete! I quickly moved to my bedroom and moved the giant chest of drawers and fired at the large wall it once was previously obstructing... and lept in. I ended up at the 1964 worlds fair--a curious affair filled with technology that seemed like magic to my mind. And that's when a man dressed in a slim black suit, of the finest fabric I had ever laid eyes on handed me a pair of goggles. The ominous glow was unlike anything from my time, or the present one. The man held them firmly in his grasp for a brief moment and uttered, "You must find her," and slowly faded from existence.

![preview](https://raw.github.com/zeroeth/oculus_aethereum/master/preview.jpg)

Oculus Aethereum
================

Preview them in action here http://www.youtube.com/watch?v=w8Tyc3dmfSE


Instructions
------------

* Get the NeoPixel library and learn more about them at http://www.adafruit.com/products/1463
* Connect two (or more) Adafruit NeoPixel Rings together
* Set the pin you connected them to in the code (Default is 4)
* Add Spots, Wobblers, Pulsars, Circlers and Growers as you see fit in the themes file!
* Adjust their speed, color, and amplitude for variation.
* Upload the code using Arduino's software.


Annotated Source
----------------

http://zeroeth.github.io/oculus_aethereum/docs/oculus_aethereum.ino.html


Nerdy Notes for the Curious
---------------------------

The style of this code is based on a `Model/View` pattern: The models (another name for classes that deal with data only) take care updating their information, in this case, the wobble or position of rotation of a light segment. The model's don't need to know about how many leds there are in a circle. The `Views` gather their respective `Models` and render them to the NeoPixel strands.

This code is object oriented uses `Pointers` to objects. Read more about the C++ constructors at http://www.learncpp.com/cpp-tutorial/101-constructor-initialization-lists/.

The Spot class has `virtual` in front of its `update()` method, this makes sure the proper method is called on its subclasses instead of the original method.

The `#IFNDEF SOMETHING_HERE` lines you see in the header files solve an annoying situation in C/C++ where including a header in multiple places gives a warning that whatever is in it has been defined twice.
