/** @file opcontrol.cpp
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

/*
 * opcontrol() runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

#include "constants.hpp"
#include "main.h"
#include "subsystems/drivetrain.hpp"
#include "subsystems/elevator.hpp"

void operatorControlMessageTask(void *parameter)
{
	while (true)
	{
		printf(
			"In teleop :) Plug in a joystick! Uses Tank drive controls.\n"
			"You can also press the Up and Down buttons in Group 8 (right side cluster) for Elevator up/down\n");
		delay(1000);
	}
}

extern Drivetrain drivetrain;
extern Elevator elevator;
void operatorControl()
{
	while (true)
	{
#pragma region Drivetrain
		// The first argument in joystick functions (1) refers to which controller to use -- driver or copilot.
		// Second arg is the axis number. Reference the physical VEX Joystick for its axes; but:
		// 1, 2, 3, 4 correspond to rx, ry, lx, and ly respectively :)

		// If you want a picture: see `VEXCortexControllerPicReference.jpeg` :)
		int leftPower = joystickGetAnalog(1, 3);
		int rightPower = joystickGetAnalog(1, 2);

		// Using tank drive for debugging purposes -- helps with wiring and direction reversal issues (as opposed to arcade drive)
		drivetrain.tankDrive(leftPower, rightPower);
#pragma endregion Drivetrain

#pragma region Elevator
		bool elevatorUpButtonPressed = joystickGetDigital(1, 8, JOY_UP);
		bool elevatorDownButtonPressed = joystickGetDigital(1, 8, JOY_DOWN);

		if (elevatorUpButtonPressed)
			elevator.set(ELEVATOR_MAX_POWER);
		else if (elevatorDownButtonPressed)
			elevator.set(-ELEVATOR_MAX_POWER);
		else
			elevator.set(0);
#pragma endregion Elevator

		// Make sure to give other tasks time to run :)
		delay(20);
	}
}
