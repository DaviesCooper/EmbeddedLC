#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

enum Encoder_Direction_Enum
{
	N,
	CW,
	CCW,
};

enum Button_Enum
{
	P1,
	M1,
	PX,
	MX,
	MANA,
	COIN,
	DICE,
	TIMER,
	BACK
};

unsigned short pollInputs();
Encoder_Direction_Enum readEncoder();

#endif