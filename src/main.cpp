#include <Arduino.h>
#include "configuration.h"
#include "stack.cpp"
#include "abstractState.h"
#include "debugState.h"
#include "inputHandling.h"
#include "animationState.h"

static Stack<AbstractState *> stateStack = Stack<AbstractState *>();
int frame = 0;
void setup()
{
	Serial.begin(115200);
	DebugState *toAdd = new DebugState();
	toAdd->i = 0;
	stateStack.push(toAdd);
}

void loop()
{
	if (frame == 10)
	{
		stateStack.push(new AnimationState());
	}
	if (frame == 20)
	{
		stateStack.pop();
	}
	if (frame == 30)
	{
		stateStack.push(new AnimationState());
	}
	stateStack.peek()->Cycle();
	frame++;
}