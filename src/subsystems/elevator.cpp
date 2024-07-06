#include "elevator.hpp"
#include "API.h"

Elevator::Elevator(int motorPin, int topLimitSwitchPin, int bottomLimitSwitchPin)
	: motorPin(motorPin), topLimitSwitchPin(topLimitSwitchPin), bottomLimitSwitchPin(bottomLimitSwitchPin)
{
	pinMode(topLimitSwitchPin, INPUT);
	pinMode(bottomLimitSwitchPin, INPUT);
}

void Elevator::set(int power)
{
	bool shouldntMove =
		(isTouchingTop() && power > 0) ||
		(isTouchingBottom() && power < 0);

	if (shouldntMove)
		motorSet(this->motorPin, 0);
	else
		motorSet(this->motorPin, power);
}

bool Elevator::isTouchingTop()
{
	return digitalRead(this->topLimitSwitchPin) == HIGH;
}

bool Elevator::isTouchingBottom()
{
	return digitalRead(this->bottomLimitSwitchPin) == HIGH;
}
