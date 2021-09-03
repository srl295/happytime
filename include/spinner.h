/**
 * Spinners for the Adafruit 7segment display
 * ©2021 Steven R. Loomis
 * SPDX-License-Identifier: Apache-2.0
 */

#include <Arduino.h>

/**
 * Spin in a circle, clockwise
 */
static uint8_t spinner_circ[] = {
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
};

/**
 * Top to bottom and then repeat
 */
static uint8_t spinner_down[] = {
    0b00000001,
    0b01000000,
    0b00001000,
};

/**
 * Top to bottom and then back again
 */
static uint8_t spinner_up_down[] = {
    0b00000001,
    0b01000000,
    0b00001000,
    0b00001000,
    0b01000000,
    0b00000001,
};

/**
 * This spinner Looks like a railroad crossing marker
 * with alternating arms
 */
static uint8_t spinner_rrxing[] = {
    (2+16),
    (4+32),
};

/**
 * Helper
 */
#define SPINNER_SIZE(k) (sizeof(k)/sizeof(k[0]))
/**
 * Get the LED segments for a particular spinner.
 * @param k which spinner array to use
 * @param x integer counter for the spinner
 */
#define SPINNER(k, x) (k[(x)%(SPINNER_SIZE(k))])
