/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"
#include "commands/Commands.hpp"
#include "RobotMap.hpp"
#include <frc/buttons/JoystickButton.h>


OI::OI() {
    // Process operator interface input here.
	DriveStick = new frc::Joystick(0);
	frc::JoystickButton* trackButton = new frc::JoystickButton(DriveStick, TRACKBUTTON);
	frc::JoystickButton* armButton = new frc::JoystickButton(DriveStick, ARMBUTTOM);
	frc::JoystickButton* debugButton = new frc::JoystickButton(DriveStick, DEBUGBUTTON);

	frc::JoystickButton* liftButton1 = new frc::JoystickButton(DriveStick, LIFTUPBUTTON);
	frc::JoystickButton* liftButton2 = new frc::JoystickButton(DriveStick, LIFTDOWNBUTTON);

	frc::JoystickButton* climbButton1 = new frc::JoystickButton(DriveStick, CLIMBUPBUTTON);
	frc::JoystickButton* climbButton2 = new frc::JoystickButton(DriveStick, CLIMBDOWNBUTTON);

	/*frc::JoystickButton* button3 = new frc::JoystickButton(DriveStick, 3);
	frc::JoystickButton* button4 = new frc::JoystickButton(DriveStick, 4);
	frc::JoystickButton* button5 = new frc::JoystickButton(DriveStick, 5);
	frc::JoystickButton* button6 = new frc::JoystickButton(DriveStick, 6);
	frc::JoystickButton* button7 = new frc::JoystickButton(DriveStick, 7);
	frc::JoystickButton* button8 = new frc::JoystickButton(DriveStick, 8);*/
	trackButton->WhenPressed(new TrackCommand());
	armButton->WhenPressed(new ArmCommand());
	debugButton->WhenPressed(new DebugCommand());
	liftButton1->WhenPressed(new LiftCommand());
	liftButton2->WhenPressed(new LiftCommand());
	climbButton1->WhenPressed(new ClimbCommand());
	climbButton2->WhenPressed(new ClimbCommand());
	frc::SmartDashboard::PutData(new DebugCommand());
	frc::SmartDashboard::PutNumber("Drive-P", DRIVEP);
	frc::SmartDashboard::PutNumber("Drive-I", DRIVEI);
	frc::SmartDashboard::PutNumber("Drive-D", DRIVED);
}
