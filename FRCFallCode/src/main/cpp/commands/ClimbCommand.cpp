/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"
#include "ctre/Phoenix.h"


#include "Robot.hpp"

ClimbCommand::ClimbCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Climb);
}

// Called just before this Command runs the first time
void ClimbCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClimbCommand::Execute() {
    Robot::Climb.runningCurrent = .5 * Robot::Climb.runningCurrent + .5 * ((Robot::Climb.climbController.GetOutputCurrent() + Robot::Climb.climbFollower.GetOutputCurrent())/2);
    //if(Robot::Climb.runningCurrent > 15){
        Robot::Climb.climbController.Set(motorcontrol::ControlMode::PercentOutput, (int)Robot::oi.DriveStick->GetRawButton(CLIMBUPBUTTON) * 1 + (int)Robot::oi.DriveStick->GetRawButton(CLIMBDOWNBUTTON) * -1);
    //}else{
        //frc::SmartDashboard::PutBoolean("toggle", !frc::SmartDashboard::GetBoolean("toggle", false));
        //Robot::Climb.climbController.Set(motorcontrol::ControlMode::PercentOutput, 0);
    //}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbCommand::IsFinished() {

    return !(Robot::oi.DriveStick->GetRawButton(CLIMBUPBUTTON) || Robot::oi.DriveStick->GetRawButton(CLIMBDOWNBUTTON));
}

// Called once after isFinished returns true
void ClimbCommand::End() {
    Robot::Climb.climbController.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbCommand::Interrupted() {}
