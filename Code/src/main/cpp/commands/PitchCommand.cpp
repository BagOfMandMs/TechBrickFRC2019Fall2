/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"

PitchCommand::PitchCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::subsystem);
}

// Called just before this Command runs the first time
void PitchCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PitchCommand::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool PitchCommand::IsFinished() { 
	return false; 
}

// Called once after isFinished returns true
void PitchCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PitchCommand::Interrupted() {}
