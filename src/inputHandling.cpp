#include <Arduino.h>
#include "inputHandling.h"
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
			bool val = digitalRead(rowCol) == LOW ? true : false;

			// Bit align it
			keys |= !val ? 1 << pos : 0;

			// Set the row to input
			pinMode(rowCol, INPUT);
		}

		// set the olumn to input
		pinMode(curCol, INPUT);
	}

	// Poll the Rotary switches as well since we have 4 bytes to work with
	bool val = digitalRead(SW) == HIGH ? true : false;
	keys |= !val ? 1 << 9 : 0;

	return keys;
}

Encoder_Direction_Enum readEncoder()
{
	static bool lastCLK = HIGH;
	static unsigned long lastInterrupt = 0;
	bool currCLK = digitalRead(CLK);
	unsigned long Timer = millis();
	if (Timer - lastInterrupt > EncoderDebounceTime && currCLK != lastCLK)
	{
		if (digitalRead(DT) == LOW)
		{
			return CW;
		}
		else
		{
			return CCW;
		}
	}
	return N;
}