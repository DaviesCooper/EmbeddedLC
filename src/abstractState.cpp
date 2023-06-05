#include <Arduino.h>
#include "utils.h"
#include "globals.h"
#include "configuration.h"
#include "abstractState.h"
#include "stack.h"

AbstractState::AbstractState()
{
    lastFrame = 0;
    lastDebug = 0;
};

AbstractState::~AbstractState(){};

void AbstractState::Cycle()
{
    unsigned long currentClock = millis();
    if ((currentClock - lastDebug) > 100)
    {
        if (DEBUG)
        {
            Serial.print("Free Memory: ");
            Serial.println(freeMemory());
            lastDebug = currentClock;
        }
    }
    while ((currentClock - lastFrame) < 1000.0 / FPS)
    {
        currentClock = millis();
    }

    Update();

    lastFrame = currentClock;
}

void AbstractState::cleanup()
{
    while (memoryCleanup.size() > 0)
        delete memoryCleanup.pop();
};

/**
 * @brief Perform this action when the P1 button is pressed.
 *
 */
void AbstractState::P1Pressed() {}

/**
 * @brief Perform this action when the M1 button is pressed.
 *
 */
void AbstractState::M1Pressed() {}

/**
 * @brief Perform this action when the PX button is pressed.
 *
 */
void AbstractState::PXPressed() {}

/**
 * @brief Perform this action when the MX button is pressed.
 *
 */
void AbstractState::MXPressed() {}

/**
 * @brief Perform this action when the Phi button is pressed.
 *
 */
void AbstractState::PhiPressed() {}

/**
 * @brief Perform this action when the Dice button is pressed.
 *
 */
void AbstractState::DicePressed() {}

/**
 * @brief Perform this action when the Mana button is pressed.
 *
 */
void AbstractState::ManaPressed() {}

/**
 * @brief Perform this action when the Timer button is pressed.
 *
 */
void AbstractState::TimerPressed() {}

/**
 * @brief Perform this action when the Back button is pressed.
 *
 */
void AbstractState::BackPressed() {}

/**
 * @brief Perform this action when the Rotary button is pressed.
 *
 */
void AbstractState::RotaryPressed() {}