#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <Arduino.h>
#include "stack.h"
#include "configuration.h"

struct AbstractState
{
static void  leftISR(){
	static unsigned long lastLInterrupt = 0;
	unsigned long LTimer = millis();
	if(LTimer - lastLInterrupt > REncoderDebounceTime){
		readREncoder(0);
		lastLInterrupt = LTimer;
	}
}

static void rightISR(){
	static unsigned long lastRInterrupt = 0;
	unsigned long RTimer = millis();
	if(RTimer - lastRInterrupt > REncoderDebounceTime){
		readREncoder(1);
		lastRInterrupt = RTimer;
	}
}

static void (*readREncoder)(uint8_t index);

public:
	AbstractState(Stack<AbstractState *> state, void (*userFunc)(uint8_t)){
		readREncoder = userFunc;
	};

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
		while ((currentClock - lastFrame) < 1000.0 / FPS){
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
	Stack<AbstractState *> stack;
};

#endif
