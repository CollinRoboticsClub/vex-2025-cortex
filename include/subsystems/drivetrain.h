#pragma once

typedef struct Drivetrain
{
	int frontLeftPin, frontRightPin, backleftPin, backRightPin;
} Drivetrain;

// Global single instance of Drivetrain.
// In init.c, call createDrivetrain() in initialize()
// extern Drivetrain drivetrain;

/// @brief Initializes and creates a `Drivetrain`.
/// @param frontLeftPin Motor pin. Can be the 2-wire ports (1 or 10) as
/// @param frontRightPin
/// @param backleftPin
/// @param backRightPin
/// @return the created `Drivetrain`
void createDrivetrain(Drivetrain *drivetrain, int frontLeftPin, int frontRightPin, int backleftPin, int backRightPin);

/// @brief Tank Drive: power is sent to the `left` and `right` sides directly. A joystick's leftY and rightY values can be used.
/// @param drivetrain A `Drivetrain*` to move.
/// @param left Power to be sent to the left side; range [-127, 127]
/// @param right Power to be sent to the right side; range [-127, 127]
void tankDrive(Drivetrain *drivetrain, int left, int right);

/// @brief Arcade Drive: a different control scheme, often bound to joysticks' leftY and rightX. Note: internally calls tankDrive.
/// @param drivetrain A `Drivetrain*` to move.
/// @param power speed at which to move forwards/backwards; range [-127, 127]
/// @param rotation speed at which to rotate; positive goes right; range [-127, 127]
void arcadeDrive(Drivetrain *drivetrain, int power, int rotation);