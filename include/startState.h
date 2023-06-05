#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "abstractState.h"

struct StartState : AbstractState
{

public:
	StartState();

	~StartState();

	void Enter();

	void Exit();

	void Update();

private:
	boolean EDH;
};

#endif
