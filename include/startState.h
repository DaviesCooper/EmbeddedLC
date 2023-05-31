#ifndef STARTSTATE_H
#define STARTSTATE_H

#include <Arduino.h>
#include "configuration.h"
#include "abstractState.h"
#include "inputHandling.h"
#include "globals.h"

struct StartState : AbstractState
{

	static void HandleISR()
	{
	}

public:
	StartState() : AbstractState() {}

	~StartState() override
	{
	}

	void Enter() override
	{
		EDH = true;
	}

	void Exit() override
	{
	}

	void LeftISR() override
	{
		EDH = false;
	}

	void RightISR() override
	{
		EDH = true;
	}

	void Update() override
	{
		unsigned short keys = pollInputs();
		if (DEBUG)
		{
			Serial.println("Start State");
			Serial.print("\t");
			// [n, ..., 0] bit address
			for (int i = 0; i < 11; i++)
			{
				byte state = bitRead(keys, i);
				Serial.print(state);
			}
			Serial.println();
		}
	}

private:
	boolean EDH = true;
};

#endif
