#include "main.h"
#include "elevator.h"

void initElevator(Elevator *elevator, int motorPin, int topLimitSwitchPin, int bottomLimitSwitchPin)
{
    elevator->motorPin = motorPin;
    elevator->topLimitSwitchPin = topLimitSwitchPin;
    elevator->bottomLimitSwitchPin = bottomLimitSwitchPin;

    pinMode(topLimitSwitchPin, INPUT);
    pinMode(bottomLimitSwitchPin, INPUT);
}

void set(Elevator *elevator, int power)
{
    motorSet(elevator->motorPin, power);
}

bool isTouchingTop(Elevator *elevator)
{
    return digitalRead(elevator->topLimitSwitchPin) == HIGH;
}

bool isTouchingBottom(Elevator *elevator)
{
    return digitalRead(elevator->bottomLimitSwitchPin) == HIGH;
}
