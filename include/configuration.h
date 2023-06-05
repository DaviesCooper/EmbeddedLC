#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// #region Program Variables

/**
 * @brief The debug variable. Used for setting things like interrupts
 * to their actual position so that the program doesn't hang forever
 * on infinite interrupts etc.
 *
 */
const bool DEBUG = true;

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
static unsigned char EncoderDebounceTime = 10;

// #endregion

// #region KY-040 Rotary Encoders
/**
 * @brief The clock pins of the rotary encoders.
 *
 */
const unsigned char CLK = 16;

/**
 * @brief The Data pins of the rotary encoders.
 *
 */
const unsigned char DT = 17;

/**
 * @brief The Switch pins of the rotary encoders.
 *
 */
const unsigned char SW = 18;

// #endregion

// #region Switch Matrix

/**
 * @brief The pins of the columns used for pull-ups of the
 * switch matrix polling.
 *
 */
unsigned char cols[] = {19, 6, 5};

/**
 * @brief The pins of the rows used for detecting if a switch
 * is pressed when polling the switch matrix.
 *
 */
unsigned char rows[] = {2, 3, 4};

/**
 * @brief The number of rows as defined by the rows array.
 *
 */
const unsigned char rowCount = sizeof(rows) / sizeof(rows[0]);

/**
 * @brief The number of columns as defined by the cols array.
 *
 */
const unsigned char colCount = sizeof(cols) / sizeof(cols[0]);

#endif
