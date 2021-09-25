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
// #include <Tone.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978



#define D_E (D_Q / 2) // 1/8
#define D_Q 200       // 1/4
#define D_H (D_Q * 2) // 1/2
#define D_HD (D_Q * 3) // dotted 1/2


// Tone spkr;
// Tone spkr1;
// Tone spkr2;

Adafruit_7segment matrix = Adafruit_7segment();

int brightness = 0;

void setup()
{
  matrix.begin(0x70);
  matrix.setBrightness(brightness);
  // spkr.begin(7);
  // spkr1.begin(8);
  // spkr2.begin(9);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

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
  #if 0
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
  #endif
}
// void myplay(uint16_t f, uint32_t d)
// {
//   while (spkr.isPlaying())
//   {
//     matrix.clear();
//     for(int qq = 0; qq<=4; qq++)
//       matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
//     matrix.writeDisplay();
//     delay(5);
//   }
//   matrix.clear();
//   for(int qq = 0; qq<=4; qq++)
//     matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
//   matrix.writeDisplay();
//   delay(100);
//   spkr.play(f, d);
// }

void myplay3(uint16_t f, uint16_t f1, uint16_t f2, uint32_t d)
{
  {
    matrix.clear();
    for(int qq = 0; qq<=4; qq++)
      matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
    matrix.writeDisplay();
    delay(5);
  }
  // if(f != 0) {
  //   tone(7, f);
  // } else {
  //   digitalWrite(7, LOW);
  // }
  if(f1 != 0) {
    tone(9, f1);
    tone(8, f1);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  delay(d);
  delay(d);

  matrix.clear();
  for(int qq = 0; qq<=4; qq++)
    matrix.writeDigitRaw(qq, SPINNER(spinner_circ, (n++)));
  matrix.writeDisplay();
  delay(5);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}


void loop()
{
  int16_t countdown = 0; // 0 minutes
  // matrix.blinkRate(HT16K33_BLINK_2HZ);
  matrix.clear();
  matrix.setBrightness(brightness);             // dimmest
  matrix.blinkRate(HT16K33_BLINK_OFF); // no blink

  int go = 0;

  int timeout = 15000; // 5 minutes before timeout

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
      timeout--;
    }

    if ( timeout <= 0 ) {
      myplay(NOTE_D2, D_Q);
      myplay(NOTE_E1, D_Q);
      myplay(NOTE_D2, D_Q);
      myplay(NOTE_E1, D_Q);
      delay(1000);
      myplay(NOTE_D2, D_Q);
      myplay(NOTE_E1, D_Q);
      myplay(NOTE_D2, D_Q);
      myplay(NOTE_E1, D_Q);
      delay(1000);
      // spkr.stop();
      matrix.setBrightness(0);
      matrix.clear();
      matrix.blinkRate(HT16K33_BLINK_HALFHZ);
      matrix.writeDigitRaw(2, 0xFFFFFFFF);
      matrix.writeDisplay();
      // matrix.blinkRate(HT16K33_BLINK_OFF);
      // matrix.writeColon();

      for(;;)
        ; // endless loop
    }
  }
  n = 0;
  while (digitalRead(3) == LOW) {
    delay(200);
    matrix.clear();
    if (n > 10) {
      matrix.writeDigitRaw(1, SPINNER(spinner_down, (n++)));
    } else {
      matrix.writeDigitRaw(1, SPINNER(spinner_rrxing, (n++)));
    }
    matrix.writeDisplay();
  }
  if (n > 10) {
    // reset
    return;
  }

  // Off and running
  matrix.blinkRate(HT16K33_BLINK_OFF);
  for (int16_t counter = countdown; counter >= 0; counter--)
  {
    printTime(counter);
    matrix.writeDisplay();
    delay(1000);

    if (digitalRead(3) == LOW) {
       n = 0;
      // pause
      matrix.clear();
      matrix.blinkRate(HT16K33_BLINK_OFF);
      while (digitalRead(3) == LOW) {
        if (n > 20) {
          matrix.writeDigitRaw(1, SPINNER(spinner_down, (n++)));
        } else {
          matrix.writeDigitRaw(1, SPINNER(spinner_rrxing, (n++)));
        }
        matrix.writeDisplay();
        delay(200);
      }
      if (n > 20) return;
      printTime(counter);
      matrix.blinkRate(HT16K33_BLINK_1HZ);
      matrix.writeDisplay();
      delay(100);
      while (digitalRead(3) == HIGH) {
        // paused
        delay(20);
        // TODO: brightness up/down?
        if (digitalRead(4) == LOW)
        {
          brightness = (brightness + 1) & 0x0F; // second
          matrix.setBrightness(brightness);
          matrix.writeDisplay();
          delay(200);
        } else if (digitalRead(5) == LOW) {
          brightness = (brightness - 1) & 0x0F; // second
          matrix.setBrightness(brightness);
          matrix.writeDisplay();
          delay(200);
        }
      }

      // unpause
      matrix.blinkRate(HT16K33_BLINK_2HZ);
      n = 0;
      // pause
      matrix.clear();
      matrix.blinkRate(HT16K33_BLINK_OFF);
      while (digitalRead(3) == HIGH) {
        if (n > 20) {
          // Exit!
          matrix.writeDigitRaw(1, SPINNER(spinner_down, (n++)));
        } else {
          matrix.writeDigitRaw(1, SPINNER(spinner_rrxing, (n++)));
        }
        matrix.writeDisplay();
        delay(200);
      }
      if (n > 20) return; // Exit

      matrix.blinkRate(HT16K33_BLINK_OFF);
      printTime(counter);
      matrix.writeDisplay();
      delay(1000);
    }
  }


#if 1
// AMF 2-voice
  myplay3(NOTE_C5, NOTE_E4,0, D_Q);
  myplay3(NOTE_C5, NOTE_C4,0,D_Q);
  myplay3(NOTE_C5, NOTE_E4,0,D_Q);
  myplay3(NOTE_G4, NOTE_D4,0,D_E);
  myplay3(NOTE_A4, NOTE_D4,0,D_E);
  myplay3(NOTE_B4, NOTE_G4,0,D_Q);
  myplay3(NOTE_C5, NOTE_E4,0,D_E);
  myplay3(NOTE_B4, NOTE_E4,0,D_E);
  myplay3(NOTE_A4, NOTE_FS4,0,D_Q);
  myplay3(NOTE_G4, NOTE_G4,0,D_Q);
#endif

#if 0
  /// AMF
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

  myplay(NOTE_C4, D_Q);
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

#endif

  delay(D_HD);
  delay(D_HD);
  delay(D_HD);
  // }
  // spkr.stop();
  // spkr1.stop();
  // spkr2.stop();

  // Done.
  matrix.setBrightness(brightness);             // dimmest
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
