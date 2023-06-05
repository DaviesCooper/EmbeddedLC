#ifndef GLOBALS_H
#define GLOBALS_H

template <typename T>
class Stack;

class AbstractState;

extern Stack<struct AbstractState *> memoryCleanup;
extern Stack<struct AbstractState *> stateStack;

#endif
