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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  matrix.begin(0x70);
  matrix.setBrightness(5);
}

uint32_t n = 0;

void loop() {
  for (uint16_t counter = 0x0; counter <= 0X50; counter++) {
    matrix.clear();
    matrix.printNumber(counter, HEX);
    if (counter >= 0x20 && counter < 0x40) {
      matrix.writeDigitRaw(0, SPINNER(spinner_circ, (n--)));
      matrix.writeDisplay();
      delay(66);
      matrix.writeDigitRaw(0, SPINNER(spinner_circ, (n--)));
      matrix.writeDisplay();
      delay(66);
      matrix.writeDigitRaw(0, SPINNER(spinner_circ, (n--)));
      matrix.writeDisplay();
      delay(66);
    } else if (counter >= 0x40 && counter <= 0x50) {
      matrix.writeDigitRaw(0, SPINNER(spinner_rrxing, (n++)));
      matrix.writeDisplay();
      delay(200);
    } else {
      matrix.writeDigitRaw(0, SPINNER(spinner_circ, (n++)));
      matrix.writeDisplay();
      delay(100);
      matrix.writeDigitRaw(0, SPINNER(spinner_circ, (n++)));
      matrix.writeDisplay();
      delay(100);
    }
  }
}
