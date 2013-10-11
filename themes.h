// Create all your movers and shakers here!

extern Adafruit_NeoPixel led_strip; /* FIXME temporary global */
extern StripView  left_eye;
extern StripView right_eye;
extern StripView  both_eyes;


namespace Theme {
  uint8_t       current_theme = 0;
  unsigned long last_millis   = 0;

  uint32_t yellow  = led_strip.Color (50, 50, 0);
  uint32_t cyan    = led_strip.Color (0, 50, 50);

  uint32_t blue    = led_strip.Color (0, 10, 50);
  uint32_t magenta = led_strip.Color (50, 0, 50);

  uint32_t pink    = led_strip.Color (50, 0, 10);

  uint32_t red     = led_strip.Color (50, 10, 0);
  uint32_t green   = led_strip.Color (0, 50, 10);

  uint32_t green2  = led_strip.Color (0, 50, 0);



  void theme1 ()
  {
    Circler* circleL1 = new Circler (/* position */ 0.0,
                                     /* width    */ 6,
                                     /* color    */ cyan);

    Pulsar* pulsarL1 =   new Pulsar (/* position */ 0.5,
                                     /* width    */ 4,
                                     /* color    */ yellow);

    Pulsar* pulsarL2 =   new Pulsar (/* position */ 0.0,
                                     /* width    */ 4,
                                     /* color    */ yellow);
    circleL1->speed = 1.0;

    left_eye.add (circleL1);
    left_eye.add (pulsarL1);
    left_eye.add (pulsarL2);


    Circler* circle1 = new Circler (/* position */ 0.0,
                                    /* width    */ 6,
                                    /* color    */ cyan);

    Pulsar* pulsar1 =   new Pulsar (/* position */ 0.0,
                                    /* width    */ 2,
                                    /* color    */ yellow);

    Pulsar* pulsar2 =   new Pulsar (/* position */ 0.33,
                                    /* width    */ 2,
                                    /* color    */ yellow);

    Pulsar* pulsar3 =   new Pulsar (/* position */ 0.66,
                                    /* width    */ 2,
                                    /* color    */ yellow);
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
    Wobbler* wobble0 = new Wobbler (/* position */ 0.50,
                                    /* width    */ 2,
                                    /* color    */ magenta);

    Wobbler* wobble1 = new Wobbler (/* position */ 0.0,
                                    /* width    */ 4,
                                    /* color    */ blue);

    wobble0->speed =  0.5;

    left_eye.add (wobble1);
    left_eye.add (wobble0);


    Grower* grower1 =  new Grower (/* position */ 0.0,
                                   /* width    */ 16,
                                   /* color    */ magenta);

    Grower* grower2 =  new Grower (/* position */ 0.0,
                                   /* width    */ 8,
                                   /* color    */ blue);

    right_eye.add (grower1);
    right_eye.add (grower2);
  }



  // Theme 3
  void theme3 ()
  {
    Pulsar*     pulsar = new Pulsar  (0.0, 32, cyan);
    Circler*  circlerL = new Circler (0.0,  2, pink);
    Circler*  circlerR = new Circler (0.0,  2, pink);

   pulsar->speed =  0.8;
   circlerL->speed = -0.5;
   circlerR->speed =  0.5;

    both_eyes.add (pulsar  );
     left_eye.add (circlerL);
    right_eye.add (circlerR);
  }



  // Theme 5
  void theme5 ()
  {
    Wobbler *wobble3 = new Wobbler (/* position */ 0.0,
                                    /* width    */ 1,
                                    /* color    */ green);

    Wobbler *wobble4 = new Wobbler (/* position */ 0.250,
                                    /* width    */ 1,
                                    /* color    */ green);

    Wobbler *wobble5 = new Wobbler (/* position */ 0.50,
                                    /* width    */ 1,
                                    /* color    */ green);

    Wobbler *wobble6 = new Wobbler (/* position */ 0.750,
                                    /* width    */ 1,
                                    /* color    */ green);

    Circler *circle3 = new Circler (/* position */ 0.0,
                                    /* width    */ 2,
                                    /* color    */ red);

    Circler *circle4 = new Circler (/* position */ 0.33,
                                    /* width    */ 2,
                                    /* color    */ red);

    Circler *circle5 = new Circler (/* position */ 0.66,
                                    /* width    */ 2,
                                    /* color    */ red);

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
                                   /* color    */ red);

    Grower* grower2 =  new Grower (/* position */ 0.33,
                                   /* width    */ 7,
                                   /* color    */ red);

    Grower* grower3 =  new Grower (/* position */ 0.66,
                                   /* width    */ 7,
                                   /* color    */ red);

    Wobbler* wobbler1 = new Wobbler (/* position */ 0.0,
                                     /* width    */ 8,
                                     /* color    */ green);


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
                                   /* color    */ green2);

    Wobbler* wobbleL1 = new Wobbler (/* position */ 0.0,
                                     /* width    */ 2,
                                     /* color    */ yellow);

    Wobbler* wobbleL2 = new Wobbler (/* position */ 0.50,
                                     /* width    */ 2,
                                     /* color    */ yellow);

    pulsarL1->speed = 0.5;

    left_eye.add (pulsarL1);
    left_eye.add (wobbleL1);
    left_eye.add (wobbleL2);


    Pulsar* pulsarR1 = new Pulsar (/* position */ 0.0,
                                   /* width    */ 8,
                                   /* color    */ green2);

    Pulsar* pulsarR2 = new Pulsar (/* position */ 0.50,
                                   /* width    */ 8,
                                   /* color    */ yellow);

    pulsarR1->offset = 0.5;
    pulsarR2->offset = 0.0;

    pulsarR1->speed = 1.2;
    pulsarR2->speed = 1.2;

    right_eye.add (pulsarR1);
    right_eye.add (pulsarR2);
  }



  // Theme 7 (half circlers)
  void theme7 ()
  {
    Circler* circlerL1 = new Circler (/* position */ 0.0,
                                      /* width    */ 8,
                                      /* color    */ blue);

    Circler* circlerL2 = new Circler (/* position */ 0.5,
                                      /* width    */ 8,
                                      /* color    */ white);


    Wobbler* wobblerR1 = new Wobbler (/* position */ 0.0,
                                      /* width    */ 8,
                                      /* color    */ cyan);
    Wobbler* wobblerR2 = new Wobbler (/* position */ 0.5,
                                      /* width    */ 8,
                                      /* color    */ magenta);

     left_eye.add (circlerL1);
     left_eye.add (circlerL2);
    right_eye.add (wobblerR1);
    right_eye.add (wobblerR2);
  }



  // Theme 8 (harmonics)
  void theme8 ()
  {
    Circler* circlerL1 = new Circler (/* position */ 0.0,  /* width */ 1,  /* color */ blue);
    Circler* circlerL2 = new Circler (/* position */ 0.0,  /* width */ 1,  /* color */ pink);

    circlerL1->speed =  1.1;
    circlerL2->speed = -1.2;

     left_eye.add (circlerL1);
     left_eye.add (circlerL2);

    Wobbler* wobblerR1 = new Wobbler (/* position */ 0.0, /* width */ 1, /* color */ cyan);
    Wobbler* wobblerR2 = new Wobbler (/* position */ 0.5, /* width */ 1, /* color */ cyan);

    Wobbler* wobblerR3 = new Wobbler (/* position */ 0.0, /* width */ 1, /* color */ magenta);
    Wobbler* wobblerR4 = new Wobbler (/* position */ 0.5, /* width */ 1, /* color */ magenta);

    wobblerR1->speed =  0.5;
    wobblerR2->speed =  0.5;

    wobblerR3->speed = -0.4;
    wobblerR4->speed = -0.4;

    right_eye.add (wobblerR1);
    right_eye.add (wobblerR2);
    right_eye.add (wobblerR3);
    right_eye.add (wobblerR4);
  }



  // Theme 9 offset stars and speed stars
  void theme9 ()
  {
    Pulsar* pulsarL1 = new Pulsar (/* position */ 0.0, /* width */ 1, /* color */ green2);
    Pulsar* pulsarL2 = new Pulsar (/* position */ 0.1, /* width */ 1, /* color */ green2);
    Pulsar* pulsarL3 = new Pulsar (/* position */ 0.4, /* width */ 1, /* color */ green );
    Pulsar* pulsarL4 = new Pulsar (/* position */ 0.5, /* width */ 1, /* color */ yellow);
    Pulsar* pulsarL5 = new Pulsar (/* position */ 0.6, /* width */ 1, /* color */ green2);
    Pulsar* pulsarL6 = new Pulsar (/* position */ 0.8, /* width */ 1, /* color */ green );

    pulsarL2->offset = 0.8;
    pulsarL3->offset = 0.67;
    pulsarL4->offset = 0.12;
    pulsarL5->offset = 0.07;
    pulsarL6->offset = 0.78;

    left_eye.add (pulsarL1);
    left_eye.add (pulsarL2);
    left_eye.add (pulsarL3);
    left_eye.add (pulsarL4);
    left_eye.add (pulsarL5);
    left_eye.add (pulsarL6);


    Pulsar* pulsarR1 = new Pulsar (/* position */ 0.0, /* width */ 1, /* color */ green2);
    Pulsar* pulsarR2 = new Pulsar (/* position */ 0.2, /* width */ 1, /* color */ green );
    Pulsar* pulsarR3 = new Pulsar (/* position */ 0.3, /* width */ 1, /* color */ green2);
    Pulsar* pulsarR4 = new Pulsar (/* position */ 0.5, /* width */ 1, /* color */ yellow);
    Pulsar* pulsarR5 = new Pulsar (/* position */ 0.8, /* width */ 1, /* color */ green2);
    Pulsar* pulsarR6 = new Pulsar (/* position */ 0.9, /* width */ 1, /* color */ green2);

    pulsarR2->speed = 0.8;
    pulsarR3->speed = 0.67;
    pulsarR4->speed = 1.12;
    pulsarR5->speed = 1.07;
    pulsarR6->speed = 0.78;

    right_eye.add (pulsarR1);
    right_eye.add (pulsarR2);
    right_eye.add (pulsarR3);
    right_eye.add (pulsarR4);
    right_eye.add (pulsarR5);
    right_eye.add (pulsarR6);
  }


  // Theme 10 (multi spiral wind)
  void theme10 ()
  {

  }


  // Wobblers from original code converted
  void themeOHS ()
  {


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

        case 6:
          theme7 ();
          break;

        case 7:
          theme8 ();
          break;

        case 8:
          theme9 ();
          break;

        default:
          broken ();
          break;
      }

      current_theme++;
      current_theme %= 9;
    }
  }
}
