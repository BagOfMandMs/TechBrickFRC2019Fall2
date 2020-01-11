/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"
#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include "Robot.hpp"
#include "frc/WPILib.h"

DefaultDriveCommand::DefaultDriveCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Drive);
}

// Called just before this Command runs the first time
void DefaultDriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DefaultDriveCommand::Execute() {

    frc::SmartDashboard::PutNumber("AxSis Y", Robot::oi.DriveStick->GetRawAxis(DRIVEAXISY));
    double joyY = Robot::oi.DriveStick->GetRawAxis(DRIVEAXISY);
    double joyZ = Robot::oi.DriveStick->GetRawAxis(DRIVEAXISZ);
    joyY = 0;
    joyZ = 0;
    if(abs(joyZ) <= TURNINGDEADBAND){
        Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, joyY);
        Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, -joyY);
    }else{
        Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, joyZ / 2);
        Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, joyZ / 2);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultDriveCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DefaultDriveCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultDriveCommand::Interrupted() {}
