#include "main.h"
#include "drivetrain.h"

void createDrivetrain(Drivetrain *drivetrain, int frontLeftPin, int frontRightPin, int backleftPin, int backRightPin)
{
	drivetrain->frontLeftPin = frontLeftPin;
	drivetrain->frontRightPin = frontRightPin;
	drivetrain->backleftPin = backleftPin;
	drivetrain->backRightPin = backRightPin;
}

void tankDrive(Drivetrain *drivetrain, int left, int right)
{
	// Reverses the right side by default!
	motorSet(drivetrain->frontLeftPin, left);
	motorSet(drivetrain->frontRightPin, -right);
	motorSet(drivetrain->backleftPin, left);
	motorSet(drivetrain->backRightPin, -right);
}

void arcadeDrive(Drivetrain *drivetrain, int power, int rotation)
{
	tankDrive(drivetrain, power + rotation, power - rotation);
}
