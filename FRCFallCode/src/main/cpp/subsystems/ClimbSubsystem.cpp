/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Subsystems.hpp"
#include "commands/Commands.hpp"

#include "RobotMap.hpp"

ClimbSubsystem::ClimbSubsystem() : frc::Subsystem("climbSubsystem"),
climbController(LEFTCLIMBID),
climbFollower(RIGHTCLIMBID),
liftMotor(LIFTMOTOR)
{
    climbController.ConfigFactoryDefault();
    climbFollower.ConfigFactoryDefault();
    climbController.SetNeutralMode(Brake);
    climbController.SetInverted(false);
    climbFollower.SetNeutralMode(Brake);
    climbFollower.SetInverted(true);
    liftMotor.SetNeutralMode(Coast);

    //climbController.ConfigSelectedliftbackSensor(liftFeedDevice::CTRE_MagEncoder_Relative, 0, kTimeoutMs);
    //climbController.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    /*climbController.ConfigNominalOutputForward(0, kTimeoutMs);
    climbController.ConfigNominalOutputReverse(0, kTimeoutMs);
    climbController.ConfigPeakOutputForward(1, kTimeoutMs);
    climbController.ConfigPeakOutputReverse(-1, kTimeoutMs);*/
    /* set closed loop gains in slot0 */
    /*climbController.Config_kF(kPIDLoopIdx, 0.1097, kTimeoutMs);
    climbController.Config_kP(kPIDLoopIdx, 0.3, kTimeoutMs);
    climbController.Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
    climbController.Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);*/

    //climbController.ConfigPeakCurrentLimit(15, 30);
    //climbController.ConfigPeakCurrentDuration(0, 30);
    //climbController.ConfigContinuousCurrentLimit(10, 30);
    //climbController.EnableCurrentLimit(true);

    //climbFollower.ConfigPeakCurrentLimit(80, 30);
    //climbFollower.ConfigPeakCurrentDuration(0, 30);
    //climbFollower.ConfigContinuousCurrentLimit(50, 30);
    //climbFollower.EnableCurrentLimit(true);

    climbFollower.Follow(climbController);
    runningCurrent = 0;

}

void ClimbSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new DefaultClimbCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
