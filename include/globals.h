#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "stack.h"

extern Stack<struct AbstractState *> memoryCleanup;
extern Stack<struct AbstractState *> stateStack;

#endif
