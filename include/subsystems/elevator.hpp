#pragma once

#include "API.h"

class Elevator
{
	int motorPin;
	int topLimitSwitchPin, bottomLimitSwitchPin;

	/// @brief Initializes an Elevator and sets pin modes.
	/// @param motorPin Pin number of the elevator motor.
	/// @param topLimitSwitchPin Digital input for the top limit switch.
	/// @param bottomLimitSwitchPin Digital input for the bottom limit switch.
public:
	Elevator(int motorPin, int topLimitSwitchPin, int bottomLimitSwitchPin)
	{
		this->motorPin = motorPin;
		this->topLimitSwitchPin = topLimitSwitchPin;
		this->bottomLimitSwitchPin = bottomLimitSwitchPin;

		pinMode(topLimitSwitchPin, INPUT);
		pinMode(bottomLimitSwitchPin, INPUT);
	}

	/// @brief Sets power, with limit switches automatically stopping it if hits them.
	/// @param power Power to be sent to the motor; range [-127, 127].
	void set(int power)
	{
		bool shouldntMove =
			(isTouchingTop() && power > 0) ||
			(isTouchingBottom() && power < 0);

		if (shouldntMove)
			motorSet(this->motorPin, 0);
		else
			motorSet(this->motorPin, power);
	}

	/// @return whether the top limit switch is triggered or not
	bool isTouchingTop()
	{
		return digitalRead(this->topLimitSwitchPin) == HIGH;
	}

	/// @return whether the bottom limit switch is triggered or not
	bool isTouchingBottom()
	{
		return digitalRead(this->bottomLimitSwitchPin) == HIGH;
	}
};
