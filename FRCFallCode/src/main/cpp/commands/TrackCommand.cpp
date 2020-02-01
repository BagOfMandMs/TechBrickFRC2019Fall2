/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"

TrackCommand::TrackCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Drive);
}

// Called just before this Command runs the first time
void TrackCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TrackCommand::Execute() {
    
    float p = frc::SmartDashboard::GetNumber("Drive-P", DRIVEP);
    float i = frc::SmartDashboard::GetNumber("Drive-I", DRIVEI);
    float d = frc::SmartDashboard::GetNumber("Drive-D", DRIVED);
    float tp = Robot::Drive.table->GetNumber("tx", 0);
    Robot::Drive.integral = (DRIVEIDECAY * tp) + ((1.0f - DRIVEIDECAY) * tp);
    float td = tp - Robot::Drive.lastValue;
    Robot::Drive.lastValue = tp;
    float power = tp * p + i * Robot::Drive.integral + d * td;
    Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, power);
    Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, power);
}

// Make this return true when this Command no longer needs to run execute()
bool TrackCommand::IsFinished() { return !Robot::oi.DriveStick->GetRawButton(TRACKBUTTON); }

// Called once after isFinished returns true
void TrackCommand::End() {
    Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, 0);
    Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrackCommand::Interrupted() {}
