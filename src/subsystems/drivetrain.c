#include "drivetrain.h"



Drivetrain createDrivetrain(int* leftMotorPins, int* rightMotorPins, int motorsPerSide)
{
    Drivetrain drivetrain;

    drivetrain.leftMotorPins = leftMotorPins;
    drivetrain.rightMotorPins = rightMotorPins;
    drivetrain.motorsPerSide = motorsPerSide;

    return drivetrain;
}

void tankDrive(Drivetrain* drivetrain, int left, int right)
{

}

void arcadeDrive(Drivetrain* drivetrain, int power, int rotation)
{
    tankDrive(drivetrain, power + rotation, power - rotation);
}
