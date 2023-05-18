#include <Arduino.h>
#include "configuration.h"
#include "stack.cpp"
#include "abstractState.h"
#include "startState.h"
#include "inputHandling.h"

static Stack<AbstractState *> stateStack = Stack<AbstractState *>();
void (*AbstractState::readREncoder)(uint8_t index) = nullptr;
int frame = 0;
void setup()
{
	
	Serial.begin(115200);
	// Attach the interrupts to the static method of the abstract state.
	attachInterrupt(digitalPinToInterrupt(CLK[0]), AbstractState::leftISR, LOW);
	attachInterrupt(digitalPinToInterrupt(CLK[0]), AbstractState::rightISR, LOW);


	StartState* start = new StartState(stateStack);
	stateStack.push(start);
}

void loop()
{
	stateStack.peek()->Cycle();
}