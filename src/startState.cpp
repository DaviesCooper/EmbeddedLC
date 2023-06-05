
#include <Arduino.h>
#include "abstractState.h"
#include "configuration.h"
#include "inputHandling.h"
#include "startState.h"

StartState::StartState() : AbstractState() {}

StartState::~StartState() {}

void StartState::Enter()
{
    EDH = true;
}

void StartState::Exit()
{
}

void StartState::Update()
{
    unsigned short keys = pollInputs();
    Encoder_Direction_Enum dir = readEncoder();
    if (DEBUG)
    {
        Serial.println("Start State");
        Serial.print("\t");
        // [n, ..., 0] bit address
        for (int i = 0; i < 11; i++)
        {
            byte state = bitRead(keys, i);
            Serial.print(state);
        }
        Serial.print(" Dir: ");
        Serial.print(dir);
        Serial.println();
    }
};
