#include "drivetrain.hpp"
#include "API.h"

Drivetrain::Drivetrain(int frontLeftPin, int frontRightPin, int backleftPin, int backRightPin)
	: frontLeftPin(frontLeftPin), frontRightPin(frontRightPin), backleftPin(backleftPin), backRightPin(backRightPin)
{
}

void Drivetrain::tankDrive(int left, int right)
{
	// Reverses the right side by default!
	motorSet(this->frontLeftPin, left);
	motorSet(this->frontRightPin, -right);
	motorSet(this->backleftPin, left);
	motorSet(this->backRightPin, -right);
}

void Drivetrain::arcadeDrive(int power, int rotation)
{
	tankDrive(power + rotation, power - rotation);
}
