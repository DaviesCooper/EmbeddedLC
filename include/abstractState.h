#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <Arduino.h>
#include "configuration.h"
#include "globals.h"

template <typename T>
class Stack;

struct AbstractState
{

public:
	AbstractState(){};

	virtual ~AbstractState() = default;

	/**
	 * @brief When entering this state do some preliminary actions.
	 *
	 */
	virtual void Enter() = 0;

	/**
	 * @brief When exiting this state do some non-memory cleanup.
	 *
	 */
	virtual void Exit() = 0;

	/**
	 * @brief What to do in the update method. Called once per frame by
	 * the cycle method.
	 *
	 */
	virtual void Update() = 0;

	/**
	 * @brief What do we do when the right ISR has been triggered
	 *
	 */
	virtual void RightISR() = 0;

	/**
	 * @brief What do we do when the left ISR has been triggered
	 *
	 */
	virtual void LeftISR() = 0;

	/**
	 * @brief Perform update at most once per frame.
	 *
	 */
	void Cycle()
	{
		unsigned long currentClock = millis();
		while ((currentClock - lastFrame) < 1000.0 / FPS)
		{
			currentClock = millis();
		}
		Update();
		lastFrame = currentClock;
	}

private:
	/**
	 * @brief The last time the frame got called.
	 *
	 */
	unsigned long lastFrame = 0;

protected:
	void cleanup()
	{
		while (memoryCleanup.size() > 0)
			delete memoryCleanup.pop();
	}
};

#endif
