/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Subsystems.hpp"
#include "commands/Commands.hpp"

#include "RobotMap.hpp"

ShooterSubsystem::ShooterSubsystem() : frc::Subsystem("ShooterSubsystem"),
data0(DATA0),
data1(DATA1)
{}

void ShooterSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new DefaultShooterCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
