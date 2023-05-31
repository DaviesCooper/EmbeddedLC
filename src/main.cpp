#include <Arduino.h>
#include "configuration.h"
#include "stack.cpp"
#include "abstractState.h"
#include "startState.h"
#include "inputHandling.h"
#include "globals.h"
#include "utils.h"

Stack<AbstractState *> memoryCleanup = Stack<AbstractState *>();
Stack<AbstractState *> stateStack = Stack<AbstractState *>();

void setup()
{

	Serial.begin(115200);
	// Attach the interrupts to the static method of the abstract state.
	attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, DEBUG ? HIGH : LOW);

	StartState *start = new StartState();
	stateStack.push(start);
}

void loop()
{
	if (DEBUG)
	{
		Serial.print("Free Memory: ");
		Serial.println(freeMemory());
	}
	stateStack.peek()->Cycle();
}