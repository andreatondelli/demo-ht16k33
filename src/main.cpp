/****************************************************************
 * Simple test of ht16k33 library turning on and off LEDs
 */

#include "ht16k33.h"

// Define the class
HT16K33 HT;

/****************************************************************/
void setup() {
  Serial.begin(57600);
  Serial.println(F("ht16k33 light test v0.01"));
  Serial.println();
  // initialize everything, 0x00 is the i2c address for the first one (0x70 is added in the class).
  HT.begin(0x00);
}

/****************************************************************/
void loop() {

  HT.clearAll();
  for (size_t i = 0; i < 5; i++)
  {

    for (size_t j = 0; j < 8; j++)
    {
      HT.setBrightness(j*2);

      u_int led = 0;
      if (i==0) led = j;
      else if (i==1) led = j+(8*2);
      else if (i==2) led = 33;
      else if (i==3) led = j+(8*6);
      else if (i==4) led = j+(8*8);

      HT.setLedNow(led);
      delay(500);
      HT.clearLedNow(led);
    }
  }
  
} // loop  