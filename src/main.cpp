#include <Arduino.h>

#include "globals.h"
#include "stack.h"
#include "abstractState.h"
#include "startState.h"

Stack<AbstractState *> memoryCleanup = Stack<AbstractState *>();
Stack<AbstractState *> stateStack = Stack<AbstractState *>();

void setup()
{
	Serial.begin(115200);
	StartState *start = new StartState();
	stateStack.push(start);
}

void loop()
{

	stateStack.peek()->Cycle();
}