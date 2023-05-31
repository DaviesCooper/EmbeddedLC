#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

#include <Arduino.h>
#include "configuration.h"

unsigned short pollInputs()
{
	unsigned short keys = 0;
	// for each column
	for (int colIndex = 0; colIndex < colCount; colIndex++)
	{

		// set the column to low (allows path to ground)
		byte curCol = cols[colIndex];
		pinMode(curCol, OUTPUT);
		digitalWrite(curCol, LOW);

		// for each row
		for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
		{

			// pullup the row
			byte rowCol = rows[rowIndex];
			pinMode(rowCol, INPUT_PULLUP);

			int pos = rowIndex * 3 + colIndex;
			// Read the pulled up row
			bool val = digitalRead(rowCol) == HIGH ? true : false;

			// Bit align it
			keys |= !val ? 1 << pos : 0;

			// Set the row to input
			pinMode(rowCol, INPUT);
		}

		// set the olumn to input
		pinMode(curCol, INPUT);
	}

	// Poll the Rotary switches as well since we have 4 bytes to work with
	bool val = digitalRead(SW) == LOW ? true : false;
	keys |= !val ? 1 << 9 : 0;

	// Delay so that you don't accidentally press a ton.
	if (keys != 0)
	{
		delay(200);
	}
	return keys;
}

static void encoderISR()
{
	static unsigned long lastInterrupt = 0;
	unsigned long Timer = millis();
	if (Timer - lastInterrupt > EncoderDebounceTime)
	{
		AbstractState *curr = stateStack.peek();
		if (digitalRead(DT) == LOW)
		{
			curr->RightISR();
		}
		else
		{
			curr->LeftISR();
		}
		lastInterrupt = Timer;
	}
}

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

#endif