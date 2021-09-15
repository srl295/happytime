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
  spkr.begin(7);

  pinMode(3, INPUT_PULLUP); // GO
  pinMode(4, INPUT_PULLUP); // S
  pinMode(5, INPUT_PULLUP); // M
  // pinMode(6, INPUT_PULLUP);

  // digitalWrite(DD8, LOW);
}

uint32_t n = 0; // spinner counter

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

void myplay(uint16_t f, uint32_t d)
{
  while (spkr.isPlaying())
  {
    matrix.clear();
    for(int qq = 0; qq<=4; qq++)
      matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
    matrix.writeDisplay();
    delay(5);
  }
  matrix.clear();
  for(int qq = 0; qq<=4; qq++)
    matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
  matrix.writeDisplay();
  delay(100);
  spkr.play(f, d);
}

void loop()
{
  int16_t countdown = 0; // 0 minutes
  // matrix.blinkRate(HT16K33_BLINK_2HZ);
  matrix.clear();
  matrix.setBrightness(0);             // dimmest
  matrix.blinkRate(HT16K33_BLINK_OFF); // no blink

  int go = 0;

  while (go == 0)
  {
    printTime(countdown);
    matrix.writeDisplay();
    // delay(20);

    if (digitalRead(3) == LOW)
    {
      go = 1;
    }
    else if (digitalRead(4) == LOW)
    {
      countdown += 1; // second
      delay(200);
    }
    else if (digitalRead(5) == LOW)
    {
      countdown += 60; // minute
      delay(200);
      // } else if (digitalRead(6) == LOW ) {
      //   countdown = 0;
      //   delay(200);
    }
    else
    {
      delay(20);
    }
  }

  while (digitalRead(3) == LOW) {
    delay(20);
    matrix.clear();
    matrix.writeDigitRaw(1, SPINNER(spinner_rrxing, (n++)));
    matrix.writeDisplay();
  }

  // Off and running
  matrix.blinkRate(HT16K33_BLINK_OFF);
  for (int16_t counter = countdown; counter >= 0; counter--)
  {
    printTime(counter);
    matrix.writeDisplay();
    delay(1000);

    if (digitalRead(3) == LOW) {
      matrix.blinkRate(HT16K33_BLINK_2HZ);
      while (digitalRead(3) == LOW) {
        delay(20);
      }
      matrix.blinkRate(HT16K33_BLINK_1HZ);
      delay(100);

      // pause 
      while (digitalRead(3) == HIGH) {
        delay(20);
      }
      // unpause
      matrix.blinkRate(HT16K33_BLINK_2HZ);
      while (digitalRead(3) == LOW) {
        delay(20);
      }
      matrix.blinkRate(HT16K33_BLINK_OFF);
    }
  }

#define D_E (D_Q / 2) // 1/8
#define D_Q 200       // 1/4
#define D_H (D_Q * 2) // 1/2
#define D_HD (D_Q * 3) // dotted 1/2

  // for (int16_t i=0; i<100;i++) {
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_G4, D_E);
  myplay(NOTE_A4, D_E);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_C5, D_E);
  myplay(NOTE_B4, D_E);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);

  myplay(NOTE_C5, D_Q);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_F4, D_E);
  myplay(NOTE_E4, D_E);
  myplay(NOTE_D4, D_Q);
  myplay(NOTE_C4, D_Q);

  myplay(NOTE_C5, D_Q);
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_G4, D_E);
  myplay(NOTE_A4, D_E);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_C5, D_E);
  myplay(NOTE_B4, D_E);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);

  myplay(NOTE_C5, D_Q);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_F4, D_E);
  myplay(NOTE_E4, D_E);
  myplay(NOTE_D4, D_Q);
  myplay(NOTE_C4, D_Q);

  myplay(NOTE_C4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_FS4, D_Q);
  myplay(NOTE_G4, D_HD);

  myplay(NOTE_C5, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_C5, D_HD);

  myplay(NOTE_B4, D_Q);
  myplay(NOTE_C5, D_Q);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_HD);

  myplay(NOTE_A4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_F4, D_Q);
  myplay(NOTE_E4, D_HD);

  myplay(NOTE_C5, D_Q);
  myplay(NOTE_B4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_G4, D_Q);
  myplay(NOTE_A4, D_Q);
  myplay(NOTE_F4, D_E);
  myplay(NOTE_E4, D_E);
  myplay(NOTE_D4, D_Q);
  myplay(NOTE_C4, D_HD);

  delay(D_HD);
  delay(D_HD);
  delay(D_HD);
  // }
  spkr.stop();

  // Done.
  matrix.setBrightness(0);
  // int p = 0;
  // int j = 0;
  // for (;;)
  // {
  //   j++;
  //   matrix.clear();
  //   matrix.writeDigitRaw(p, SPINNER(spinner_circ, (n++)));
  //   matrix.writeDisplay();
  //   delay(66);
  //   if ((j % 127) == 0)
  //   {
  //     p++;
  //     if (p == 2)
  //       p++;
  //     if (p == 5)
  //       p = 0;
  //   }
  // }

  // // Done - sleep
  // matrix.clear();
  // matrix.write('0');
  // matrix.write('0');
  // matrix.write(':');
  // matrix.write('0');
  // matrix.write('0');
  // matrix.writeDisplay();
  // delay(2000);
  // delay(1000 * 60 * 5); // go back and get another number after 5 min
}
