/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"
#include "commands/Commands.hpp"

#include <frc/WPILib.h>

OI::OI() {
    // Process operator interface input here.
	frc::Joystick* joy = new frc::Joystick(1);
	frc::JoystickButton* button1 = new frc::JoystickButton(joy, 1);
	frc::JoystickButton* button2 = new frc::JoystickButton(joy, 2);
	frc::JoystickButton* button3 = new frc::JoystickButton(joy, 3);
	frc::JoystickButton* button4 = new frc::JoystickButton(joy, 4);
	frc::JoystickButton* button5 = new frc::JoystickButton(joy, 5);
	frc::JoystickButton* button6 = new frc::JoystickButton(joy, 6);
	frc::JoystickButton* button7 = new frc::JoystickButton(joy, 7);
	frc::JoystickButton* button8 = new frc::JoystickButton(joy, 8);
	button1->WhenPressed(new ExampleCommand());
}
