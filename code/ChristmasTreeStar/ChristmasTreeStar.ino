/*********************************************************************************************************
 * Autore:  Marco Grandini                                                                               *
 * Data:    05/01/2024                                                                                   *
 * Titolo:  Puntale Albero di Natale con LED NeoPixel                                                    *
 *********************************************************************************************************/
#include <Adafruit_NeoPixel.h>
#define PIN 2         // input pin Neopixel is attached to
#define NUMPIXELS 11  // number of neopixels in strip
Adafruit_NeoPixel p
ixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pixels.begin();     // Initialize the NeoPixel library.
//  Serial.begin(9600);
}

void loop() {
  //Random_01();
  sine();
}

void sine() {
  int Cicli = 20000;
  int Pause = 0;
  static float PhaseRed = 0;
  static float PhaseGreen = 2.093;
  static float PhaseBlue = 4.186;
  static float PhaseInc = 0.01;
  static float Phaseshift = 6.28 / NUMPIXELS;
  int ValRed;
  int ValGreen;
  int ValBlue;

  pixels.clear();
  pixels.show();
  for (int Ciclo = 0; Ciclo < Cicli; Ciclo++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      ValRed=int((sin(PhaseRed+Phaseshift*(i+1))+1)*127.5);
      ValGreen=int((sin(PhaseGreen+Phaseshift*(i+1))+1)*127.5);
      ValBlue=int((sin(PhaseBlue+Phaseshift*(i+1))+1)*127.5);
      pixels.setPixelColor(i, pixels.Color(ValRed, ValGreen, ValBlue));


        //*****************************
        //** Debug (Plotter seriale) **
        //*****************************

        // Serial.print(i);
        // Serial.print("\t");
        // Serial.print(ValRed);
        // Serial.print("\t");
        // Serial.print(ValGreen);
        // Serial.print("\t");
        // Serial.println(ValBlue);
        //*****************************

      if (i==0){

        PhaseRed+=PhaseInc;
        PhaseGreen+=PhaseInc;
        PhaseBlue+=PhaseInc;
        if (PhaseRed >=0 && PhaseRed < 3.14){
          digitalWrite(LED_BUILTIN, HIGH);
        } else {
          digitalWrite(LED_BUILTIN, LOW);
        }
        if (PhaseRed > 6.28){PhaseRed = 0;}
        if (PhaseGreen > 6.28){PhaseGreen = 0;}
        if (PhaseBlue > 6.28){PhaseBlue = 0;}
      }
    }
    pixels.show();
    delay(Pause);

  }
}
