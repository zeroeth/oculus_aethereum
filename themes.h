// Create all your movers and shakers here!

extern Adafruit_NeoPixel led_strip; /* FIXME temporary global */
extern StripView  left_eye;
extern StripView right_eye;
extern StripView  both_eyes;


namespace Theme {
  uint8_t       current_theme = 0;
  unsigned long last_millis   = 0;


  void theme1 ()
  {
    Circler* circleL1 = new Circler (/* position */ 0.0,
                                     /* width    */ 6,
                                     /* color    */ led_strip.Color (0, 5, 5));

    Pulsar* pulsarL1 =   new Pulsar (/* position */ 0.5,
                                     /* width    */ 4,
                                     /* color    */ led_strip.Color (5, 5, 0));

    Pulsar* pulsarL2 =   new Pulsar (/* position */ 0.0,
                                     /* width    */ 4,
                                     /* color    */ led_strip.Color (5, 5, 0));
    circleL1->speed = 1.0;

    left_eye.add (circleL1);
    left_eye.add (pulsarL1);
    left_eye.add (pulsarL2);


    Circler* circle1 = new Circler (/* position */ 0.0,
                                    /* width    */ 6,
                                    /* color    */ led_strip.Color (0, 5, 5));

    Pulsar* pulsar1 =   new Pulsar (/* position */ 0.0,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 5, 0));

    Pulsar* pulsar2 =   new Pulsar (/* position */ 0.33,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 5, 0));

    Pulsar* pulsar3 =   new Pulsar (/* position */ 0.66,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 5, 0));
    circle1->speed = -1.0;
    pulsar1->speed =  2.0;
    pulsar2->speed =  2.0;
    pulsar3->speed =  2.0;

    right_eye.add (circle1);
    right_eye.add (pulsar1);
    right_eye.add (pulsar2);
    right_eye.add (pulsar3);
  }



  // Theme 2
  void theme2 ()
  {
    Wobbler* wobble0 = new Wobbler (/* position */ 0.5,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 0, 5));

    Wobbler* wobble1 = new Wobbler (/* position */ 0.0,
                                    /* width    */ 4,
                                    /* color    */ led_strip.Color (0, 0, 5));

    wobble0->speed =  0.5;

    left_eye.add (wobble1);
    left_eye.add (wobble0);


    Grower* grower1 =  new Grower (/* position */ 0.0,
                                   /* width    */ 16,
                                   /* color    */ led_strip.Color (5, 0, 5));

    Grower* grower2 =  new Grower (/* position */ 0.0,
                                   /* width    */ 8,
                                   /* color    */ led_strip.Color (0, 1, 5));

    right_eye.add (grower1);
    right_eye.add (grower2);
  }



  // Theme 3
  void theme3 ()
  {
    Pulsar*         pulsar = new Pulsar  (0.0, 32, led_strip.Color (0, 5, 5));
    Circler*  spot_circler = new Circler (0.1,  2, led_strip.Color (5, 0, 1));

   pulsar->speed =  0.8;
   spot_circler->speed = -0.4;

    both_eyes.add ( pulsar);
    both_eyes.add ( spot_circler);
  }


  // Wobblers from original code converted
  void themeOHS ()
  {


  }


  // Theme 5
  void theme5 ()
  {
    Wobbler *wobble3 = new Wobbler (/* position */ 0.0,
                                    /* width    */ 1,
                                    /* color    */ led_strip.Color (0, 5, 1));

    Wobbler *wobble4 = new Wobbler (/* position */ 0.25,
                                    /* width    */ 1,
                                    /* color    */ led_strip.Color (0, 5, 1));

    Wobbler *wobble5 = new Wobbler (/* position */ 0.5,
                                    /* width    */ 1,
                                    /* color    */ led_strip.Color (0, 5, 1));

    Wobbler *wobble6 = new Wobbler (/* position */ 0.75,
                                    /* width    */ 1,
                                    /* color    */ led_strip.Color (0, 5, 1));

    Circler *circle3 = new Circler (/* position */ 0.0,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 1, 0));

    Circler *circle4 = new Circler (/* position */ 0.33,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 1, 0));

    Circler *circle5 = new Circler (/* position */ 0.66,
                                    /* width    */ 2,
                                    /* color    */ led_strip.Color (5, 1, 0));

   wobble3->speed = 0.4;
   wobble4->speed = 0.4;
   wobble5->speed = 0.4;
   wobble6->speed = 0.4;
   circle3->speed = 0.6;
   circle4->speed = 0.6;
   circle5->speed = 0.6;

    left_eye.add (wobble3);
    left_eye.add (wobble4);
    left_eye.add (wobble5);
    left_eye.add (wobble6);
   right_eye.add (circle3);
   right_eye.add (circle4);
   right_eye.add (circle5);
  }


  // Theme 4
  void theme4 ()
  {
    Grower* grower1 =  new Grower (/* position */ 0.0,
                                   /* width    */ 7,
                                   /* color    */ led_strip.Color (5, 0, 0));

    Grower* grower2 =  new Grower (/* position */ 0.33,
                                   /* width    */ 7,
                                   /* color    */ led_strip.Color (5, 0, 0));

    Grower* grower3 =  new Grower (/* position */ 0.66,
                                   /* width    */ 7,
                                   /* color    */ led_strip.Color (5, 0, 0));

    Wobbler* wobbler1 = new Wobbler (/* position */ 0.0,
                                     /* width    */ 8,
                                     /* color    */ led_strip.Color (0, 5, 1));


    wobbler1->speed = 0.6;

    left_eye.add (grower1);
    left_eye.add (grower2);
    left_eye.add (grower3);
   right_eye.add (wobbler1);

  }


  void theme6()
  {
    Pulsar* pulsarL1 = new Pulsar (/* position */ 0.0,
                                   /* width    */ 16,
                                   /* color    */ led_strip.Color (1, 4, 0));

    Wobbler* wobbleL1 = new Wobbler (/* position */ 0.0,
                                     /* width    */ 2,
                                     /* color    */ led_strip.Color (5, 5, 0));

    Wobbler* wobbleL2 = new Wobbler (/* position */ 0.5,
                                     /* width    */ 2,
                                     /* color    */ led_strip.Color (5, 5, 0));

    pulsarL1->speed = 0.5;

    left_eye.add (pulsarL1);
    left_eye.add (wobbleL1);
    left_eye.add (wobbleL2);


    Pulsar* pulsarR1 = new Pulsar (/* position */ 0.0,
                                   /* width    */ 8,
                                   /* color    */ led_strip.Color (1, 4, 0));

    Pulsar* pulsarR2 = new Pulsar (/* position */ 0.5,
                                   /* width    */ 8,
                                   /* color    */ led_strip.Color (5, 5, 0));

    pulsarR1->speed = 0.44;
    pulsarR2->speed = 1.33;

    right_eye.add (pulsarR1);
    right_eye.add (pulsarR2);
  }


  void broken ()
  {
    Pulsar* pulsar1 = new Pulsar (/* position */ 0.5,
                                  /* width    */ 32,
                                  /* color    */ led_strip.Color (5, 1, 1));

    both_eyes.add (pulsar1);

  }


  void switch_every (uint16_t delay)
  {
    if(millis() - last_millis > delay)
    {
      last_millis = millis();

       left_eye.unload_theme ();
      right_eye.unload_theme ();
      both_eyes.unload_theme ();

      switch(current_theme)
      {
        case 0:
          theme1 ();
          break;

        case 1:
          theme2 ();
          break;

        case 2:
          theme3 ();
          break;

        case 3:
          theme4 ();
          break;

        case 4:
          theme5 ();
          break;

        case 5:
          theme6 ();
          break;

        default:
          broken ();
          break;
      }

      current_theme++;
      current_theme %= 6;
    }
  }
}
