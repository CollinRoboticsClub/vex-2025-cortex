#pragma once

#include "API.h"

// Global single instance of Drivetrain.
// In init.c, call initDrivetrain() in initialize()
// extern Drivetrain drivetrain;

class Drivetrain
{
	int frontLeftPin;
	int frontRightPin;
	int backleftPin;
	int backRightPin;

public:
	/// @param frontLeftPin Motor pin. Can be the 2-wire ports (1 or 10) as
	/// @param frontRightPin
	/// @param backleftPin
	/// @param backRightPin
	/// @return the created `Drivetrain`
	Drivetrain(int frontLeftPin, int frontRightPin, int backleftPin, int backRightPin)
	{
		this->frontLeftPin = frontLeftPin;
		this->frontRightPin = frontRightPin;
		this->backleftPin = backleftPin;
		this->backRightPin = backRightPin;
	}

	/// @brief Tank Drive: power is sent to the `left` and `right` sides directly. A joystick's leftY and rightY values can be used.
	/// @param left Power to be sent to the left side; range [-127, 127]
	/// @param right Power to be sent to the right side; range [-127, 127]
	void tankDrive(int left, int right)
	{
		// Reverses the right side by default!
		motorSet(this->frontLeftPin, left);
		motorSet(this->frontRightPin, -right);
		motorSet(this->backleftPin, left);
		motorSet(this->backRightPin, -right);
	}

	/// @brief Arcade Drive: a different control scheme, often bound to joysticks' leftY and rightX. Note: internally calls tankDrive.
	/// @param power speed at which to move forwards/backwards; range [-127, 127]
	/// @param rotation speed at which to rotate; positive goes right; range [-127, 127]
	void arcadeDrive(int power, int rotation)
	{
		tankDrive(power + rotation, power - rotation);
	}
};
