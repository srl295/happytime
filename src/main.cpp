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
  matrix.setBrightness(5);
}

void loop() {
  matrix.blinkRate(HT16K33_BLINK_OFF);
  for (uint16_t counter = 15; counter > 0; counter--) {
    matrix.println(8800 + counter);
    matrix.setBrightness(counter);
  for (uint16_t counter = 0; counter <= 8; counter++) {
    matrix.println(counter);
    matrix.writeDigitRaw(0, 1 << counter);
    matrix.writeDisplay();
    delay(500);
  }
}
