#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <Arduino.h>

// #region Program Variables

/**
 * @brief The FPS to run the main program loop at.
 * This program uses FPS to determine when to display
 * frames of animation etc. so setting this will affect
 * the speed at which the program functions.
 *
 */
const unsigned int FPS = 5;

/**
 * @brief The time in milliseconds you should wait when
 * a rotary encoder detects a rotation. Avoids bouncing.
 * TODO: Modify this to use impossible sequence detection
 * https://www.pinteric.com/rotary.html
 *
 */
static byte REncoderDebounceTime = 5;

/**
 * @brief If we are in debug mode.
 *
 */
bool DEBUG = true;

// #endregion

// #region KY-040 Rotary Encoders
/**
 * @brief The clock pins of the rotary encoders.
 *
 */
const int CLK[] = {2, 3};

/**
 * @brief The Data pins of the rotary encoders.
 *
 */
const int DT[] = {5, 6};

/**
 * @brief The Switch pins of the rotary encoders.
 *
 */
const int SW[] = {4, 13};

// #endregion

// #region Switch Matrix

/**
 * @brief The pins of the columns used for pull-ups of the
 * switch matrix polling.
 *
 */
byte cols[] = {9, 8, 7};

/**
 * @brief The pins of the rows used for detecting if a switch
 * is pressed when polling the switch matrix.
 *
 */
byte rows[] = {12, 11, 10};

/**
 * @brief The number of rows as defined by the rows array.
 *
 */
const int rowCount = sizeof(rows) / sizeof(rows[0]);

/**
 * @brief The number of columns as defined by the cols array.
 *
 */
const int colCount = sizeof(cols) / sizeof(cols[0]);

#endif
