#ifndef DEBUGSTATE_H
#define DEBUGSTATE_H

#include <Arduino.h>
#include "configuration.h"
#include "abstractState.h"

struct DebugState : AbstractState
{
public:
	int i = 0;
	DebugState() : AbstractState() {}
	void Enter() override
	{
		Serial.print("Enter Called on Debug ");
		Serial.println(i);
	}

	void Exit() override
	{
		Serial.print("Exit Called on Debug ");
		Serial.println(i);
	}

	void Update() override
	{
		Serial.print("Update Called on Debug ");
		Serial.println(i);
	}
};

#endif
