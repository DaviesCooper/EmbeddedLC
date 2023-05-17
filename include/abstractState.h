#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <Arduino.h>
#include "configuration.h"

struct AbstractState
{
public:
	AbstractState(){};
	~AbstractState(){};
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
	 * @brief Perform update at most once per frame.
	 *
	 */
	void Cycle()
	{
		unsigned long currentClock = millis();
		while ((currentClock - lastFrame) < 1000.0 / FPS)
			currentClock = millis();
		Update();
		lastFrame = currentClock;
	}

private:
	/**
	 * @brief The last time the frame got called.
	 *
	 */
	unsigned long lastFrame = 0;
};

#endif
