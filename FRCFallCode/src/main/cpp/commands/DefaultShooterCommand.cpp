/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"

DefaultShooterCommand::DefaultShooterCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Shooter);
}

// Called just before this Command runs the first time
void DefaultShooterCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DefaultShooterCommand::Execute() {
    //Robot::Shooter.data0.Set(false);
    //Robot::Shooter.data1.Set(false);
    //Robot::Shooter.ShooterController.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultShooterCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DefaultShooterCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultShooterCommand::Interrupted() {}
