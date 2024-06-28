#pragma once

typedef struct Drivetrain {
    int* leftMotorPins;
    int* rightMotorPins;
    int motorsPerSide;
} Drivetrain;


/// @brief Initializes and creates a `Drivetrain`.
/// @param leftMotorPins Array of pins for the motors on the left side.
/// @param rightMotorPins Array of pins for the motors on the right side.
/// @param motorsPerSide Number of motors per side; assuming symmetry...
/// @return the created `Drivetrain`
Drivetrain createDrivetrain(int* leftMotorPins, int* rightMotorPins, int motorsPerSide);


/// @brief Tank Drive: power is sent to the `left` and `right` sides directly. A joystick's leftY and rightY values can be used.
/// @param drivetrain A `Drivetrain*` to move.
/// @param left Power to be sent to the left side; range [-127, 127]
/// @param right Power to be sent to the right side; range [-127, 127]
void tankDrive(Drivetrain* drivetrain, int left, int right);


/// @brief Arcade Drive: a different control scheme, often bound to joysticks' leftY and rightX. Note: internally calls tankDrive.
/// @param drivetrain A `Drivetrain*` to move.
/// @param power speed at which to move forwards/backwards; range [-127, 127]
/// @param rotation speed at which to rotate; positive goes right; range [-127, 127]
void arcadeDrive(Drivetrain* drivetrain, int power, int rotation);

