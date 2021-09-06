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

Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
  matrix.begin(0x70);
  matrix.setBrightness(5);
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

void loop()
{
  int countdown = 2 * 60; // 2 minutes
  for (int16_t counter = countdown; counter >= 0; counter--)
  {
    printTime(counter);
    matrix.writeDisplay();
    delay(1000);
  }

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
