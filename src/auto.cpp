/** @file auto.cpp
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "constants.hpp"
#include "main.h"
#include "subsystems/drivetrain.hpp"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
extern Drivetrain drivetrain;

void autonomous()
{
	printf("Entered autonomous task!\n");
	printf("Driving in a square! :)\n");

	for (int i = 0; i < 4; i++)
	{
		printf("LOOP ITER %d\n", i);

		printf("\tDriving forwards\n");
		drivetrain.arcadeDrive(DRIVETRAIN_MAX_POWER, 0);
		delay(2000);
		drivetrain.arcadeDrive(0, 0);
		delay(500);

		printf("\tTurning right\n");
		drivetrain.arcadeDrive(0, DRIVETRAIN_MAX_POWER);
		delay(2000);
		drivetrain.arcadeDrive(0, 0);
		delay(500);
	}

	// Make sure you're not starving tasks!
	delay(20);
}
