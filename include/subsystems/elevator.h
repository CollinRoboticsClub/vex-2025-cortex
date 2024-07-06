#pragma once

typedef struct Elevator
{
    int motorPin;
    int topLimitSwitchPin, bottomLimitSwitchPin;
} Elevator;

/// @brief Initializes an Elevator and sets pin modes.
/// @param elevator An Elevator* to initialize.
/// @param motorPin Pin number of the elevator motor.
/// @param topLimitSwitchPin Digital input for the top limit switch.
/// @param bottomLimitSwitchPin Digital input for the bottom limit switch.
void initElevator(Elevator *elevator, int motorPin, int topLimitSwitchPin, int bottomLimitSwitchPin);

/// @brief Sets power, with limit switches automatically stopping it if hits them.
/// @param elevator An Elevator* to set
/// @param power Power to be sent to the motor; range [-127, 127].
void set(Elevator *elevator, int power);

#include <stdbool.h> // wow, C really doesn't have booleans!
/// @return whether the top limit switch is triggered or not
bool isTouchingTop(Elevator* elevator);
/// @return whether the bottom limit switch is triggered or not
bool isTouchingBottom(Elevator* elevator);