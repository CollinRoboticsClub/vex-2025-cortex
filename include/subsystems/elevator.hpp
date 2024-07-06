#pragma once

class Elevator
{
private:
	int motorPin;
	int topLimitSwitchPin, bottomLimitSwitchPin;

	/// @brief Initializes an Elevator and sets pin modes.
	/// @param motorPin Pin number of the elevator motor.
	/// @param topLimitSwitchPin Digital input for the top limit switch.
	/// @param bottomLimitSwitchPin Digital input for the bottom limit switch.
public:
	Elevator(int motorPin, int topLimitSwitchPin, int bottomLimitSwitchPin);

	/// @brief Sets power, with limit switches automatically stopping it if hits them.
	/// @param power Power to be sent to the motor; range [-127, 127].
	void set(int power);

	/// @return whether the top limit switch is triggered or not
	bool isTouchingTop();

	/// @return whether the bottom limit switch is triggered or not
	bool isTouchingBottom();
};
