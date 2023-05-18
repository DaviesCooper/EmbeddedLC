#ifndef STARTSTATE_H
#define STARTSTATE_H

#include <Arduino.h>
#include "configuration.h"
#include "abstractState.h"
#include "inputHandling.h"

struct StartState : AbstractState
{

static void HandleISR(uint8_t index){

}

public:
	StartState(Stack<AbstractState *> state) : AbstractState(state, HandleISR) {}
	void Enter() override
	{
        EDH = true;
        
	}

	void Exit() override
	{
       stack.pop();
	}

	void Update() override
	{
		Serial.println("In cycle");
	}

private:
	boolean EDH = true;
};

#endif
