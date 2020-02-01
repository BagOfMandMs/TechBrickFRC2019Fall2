/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"

DebugCommand::DebugCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Drive);
}

// Called just before this Command runs the first time
void DebugCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DebugCommand::Execute() {
    frc::SmartDashboard::PutBoolean("toggle", !frc::SmartDashboard::GetBoolean("toggle", false));
}

// Make this return true when this Command no longer needs to run execute()
bool DebugCommand::IsFinished() { return !Robot::oi.DriveStick->GetRawButton(DEBUGBUTTON); }

// Called once after isFinished returns true
void DebugCommand::End() {
    
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DebugCommand::Interrupted() {}
