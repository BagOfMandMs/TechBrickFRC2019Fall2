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

LiftCommand::LiftCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Climb);
}

// Called just before this Command runs the first time
void LiftCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LiftCommand::Execute() {
    Robot::Climb.liftMotor.Set(motorcontrol::ControlMode::PercentOutput, (int)Robot::oi.DriveStick->GetRawButton(LIFTUPBUTTON) * 1 + (int)Robot::oi.DriveStick->GetRawButton(LIFTDOWNBUTTON) * -1);
    Robot::Climb.runningCurrent = .5 * Robot::Climb.runningCurrent + .5 * ((Robot::Climb.climbController.GetOutputCurrent() + Robot::Climb.climbFollower.GetOutputCurrent())/2);
    
}

// Make this return true when this Command no longer needs to run execute()
bool LiftCommand::IsFinished() { return !(Robot::oi.DriveStick->GetRawButton(LIFTUPBUTTON) || Robot::oi.DriveStick->GetRawButton(LIFTDOWNBUTTON)); }

// Called once after isFinished returns true
void LiftCommand::End() {
    Robot::Climb.liftMotor.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftCommand::Interrupted() {}
