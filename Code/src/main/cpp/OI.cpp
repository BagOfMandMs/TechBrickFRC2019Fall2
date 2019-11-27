/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"
#include "commands/Commands.hpp"
#include "RobotMap.hpp"



OI::OI() {
    // Process operator interface input here.
	DriveStick = new frc::Joystick(0);
	frc::JoystickButton* trackButton = new frc::JoystickButton(DriveStick, TRACKBUTTON);
	frc::JoystickButton* debugButton = new frc::JoystickButton(DriveStick, DEBUGBUTTON);
	/*frc::JoystickButton* button3 = new frc::JoystickButton(DriveStick, 3);
	frc::JoystickButton* button4 = new frc::JoystickButton(DriveStick, 4);
	frc::JoystickButton* button5 = new frc::JoystickButton(DriveStick, 5);
	frc::JoystickButton* button6 = new frc::JoystickButton(DriveStick, 6);
	frc::JoystickButton* button7 = new frc::JoystickButton(DriveStick, 7);
	frc::JoystickButton* button8 = new frc::JoystickButton(DriveStick, 8);*/
	trackButton->WhenPressed(new TrackCommand());
	debugButton->WhenPressed(new DebugCommand());
}
