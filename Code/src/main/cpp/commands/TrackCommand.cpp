/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"
#include "frc/WPILib.h"

TrackCommand::TrackCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Drive);
}

// Called just before this Command runs the first time
void TrackCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TrackCommand::Execute() {
    
    float kp = 1.0f / 20.0f;
    float thresh = 2.5f * kp;
    float tx = Robot::Drive.table->GetNumber("tx", 0);
    tx *= kp;
    if(tx > thresh || tx < -thresh){
        Robot::Shooter.armPin.Set(frc::Relay::kOff);
        Robot::Shooter.firePin.Set(frc::Relay::kOff);
        Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, tx);
        Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, tx);
    }else{
        if(tx != 0.0){
            Robot::Shooter.armPin.Set(frc::Relay::kOn);
            if(Robot::oi.DriveStick->GetRawButton(FIREBUTTON)){
                Robot::Shooter.firePin.Set(frc::Relay::kOn);
            }else{
                Robot::Shooter.firePin.Set(frc::Relay::kOff);
            }
        }
        Robot::Drive.RightController.Set(motorcontrol::ControlMode::PercentOutput, 0);
        Robot::Drive.LeftController.Set(motorcontrol::ControlMode::PercentOutput, 0);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool TrackCommand::IsFinished() { return !Robot::oi.DriveStick->GetRawButton(TRACKBUTTON); }

// Called once after isFinished returns true
void TrackCommand::End() {
    Robot::Shooter.armPin.Set(frc::Relay::kOff);
    Robot::Shooter.firePin.Set(frc::Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrackCommand::Interrupted() {}
