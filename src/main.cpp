/**
 * Happy Clock.
 * ©2021 Steven R. Loomis
 * SPDX-License-Identifier: Apache-2.0
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  matrix.begin(0x70);
}

void loop() {
  matrix.blinkRate(HT16K33_BLINK_OFF);
  for (uint16_t counter = 15; counter > 0; counter--) {
    matrix.println(8800 + counter);
    matrix.setBrightness(counter);
    matrix.writeDisplay();
    delay(100);
  }
  matrix.blinkRate(HT16K33_BLINK_HALFHZ);
  for (uint16_t counter = 0; counter <= 15; counter++) {
    matrix.println(8800 + counter);
    matrix.setBrightness(counter);
    matrix.writeDisplay();
    delay(100);
  }
  matrix.blinkRate(HT16K33_BLINK_1HZ);
  for (uint16_t counter = 0; counter <= 15; counter++) {
    matrix.println(8800 + counter);
    matrix.setBrightness(counter);
    matrix.writeDisplay();
    delay(100);
  }
}