/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Commands.hpp"

#include "Robot.hpp"

ArmCommand::ArmCommand() {
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::Shooter);
}

// Called just before this Command runs the first time
void ArmCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmCommand::Execute() {
    //double motorOutput = Robot::Shooter.ShooterController.GetMotorOutputPercent();

    double targetVelocity_UnitsPer100ms = Robot::oi.DriveStick->GetRawAxis(3) * 1500.0 * 4096 / 600;

    Robot::Shooter.ShooterController.Set(ControlMode::Velocity, targetVelocity_UnitsPer100ms);

     //Robot::Shooter.ShooterController.Set(motorcontrol::ControlMode::PercentOutput, Robot::oi.DriveStick->GetRawAxis(3));
     if(Robot::oi.DriveStick->GetRawButton(FIREBUTTON)){
         Robot::Shooter.FeedMotor.Set(motorcontrol::ControlMode::PercentOutput, 1);
     }else{
         Robot::Shooter.FeedMotor.Set(motorcontrol::ControlMode::PercentOutput, 0);
     }
}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommand::IsFinished() { return !Robot::oi.DriveStick->GetRawButton(ARMBUTTOM); }

// Called once after isFinished returns true
void ArmCommand::End() {
    Robot::Shooter.ShooterController.Set(motorcontrol::ControlMode::PercentOutput, 0);
    Robot::Shooter.FeedMotor.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommand::Interrupted() {}
