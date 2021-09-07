/**
 * Happy Clock.
 * ©2021 Steven R. Loomis
 * SPDX-License-Identifier: Apache-2.0
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "spinner.h"
#include <Tone.h>

Tone spkr;

Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
  matrix.begin(0x70);
  matrix.setBrightness(5);
  spkr.begin(DD7);
}

uint32_t n = 0;

void printTime2(int m, int s)
{
  matrix.clear();
  if (m > 0)
  {
    int m1 = m % 10;
    int m0 = (m - m1) / 10;
    if (m0)
    {
      matrix.writeDigitNum(0, m0, false);
    }
    matrix.writeDigitNum(1, m1, false);
  }
  // digit '2'
  matrix.drawColon(s % 2 == 0);
  int s1 = s % 10;
  int s0 = (s - s1) / 10;
  matrix.writeDigitNum(3, s0, false);
  matrix.writeDigitNum(4, s1, false);
}

void printTime(int ss)
{
  int s = ss % 60;
  int m = (ss - s) / 60;
  printTime2(m, s);
}

void myplay(uint16_t f, uint32_t d) {
  while(spkr.isPlaying()) {
    delay(5);
  }
  delay(100);
  spkr.play(f, d);
}

void loop()
{
  int countdown =  2*60; // 2 minutes
  for (int16_t counter = countdown; counter >= 0; counter--)
  {
    printTime(counter);
    matrix.writeDisplay();
    delay(1000);
  }

  #define D_Q 200

  // for (int16_t i=0; i<100;i++) {
    myplay(NOTE_C5, D_Q);
    myplay(NOTE_C5, D_Q);
    myplay(NOTE_C5, D_Q);
    myplay(NOTE_G4, D_Q);
    myplay(NOTE_A4, D_Q);
    myplay(NOTE_B4, D_Q);
    myplay(NOTE_C5, D_Q);
    myplay(NOTE_B4, D_Q);
    myplay(NOTE_A4, D_Q);
    myplay(NOTE_G4, D_Q);
  // }
  // spkr.stop();



  // Done.
  matrix.setBrightness(0);
  int p = 0;
  int j = 0;
  for (;;)
  {
    j++;
    matrix.clear();
    matrix.writeDigitRaw(p, SPINNER(spinner_circ, (n++)));
    matrix.writeDisplay();
    delay(66);
    if ((j % 127) == 0) {
      p++;
      if(p == 2) p++;
      if(p == 5) p = 0;
    }
  }
}
