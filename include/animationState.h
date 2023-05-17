#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

#include <Arduino.h>
#include "configuration.h"
#include "abstractState.h"

struct AnimationState : AbstractState
{
public:
	int i = 0;
	AnimationState() : AbstractState() {}
	void Enter() override
	{
		Serial.print("Enter Called on AnimationState ");
		Serial.println(i);
	}

	void Exit() override
	{
		Serial.print("Exit Called on AnimationState ");
		Serial.println(i);
	}

	void Update() override
	{
		Serial.print("Frame:");
		Serial.println(frame);
		frame++;
	}

private:
	int frame = 0;
};

#endif
