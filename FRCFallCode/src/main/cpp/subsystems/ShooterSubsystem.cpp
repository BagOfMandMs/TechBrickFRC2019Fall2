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
ShooterController(LEFTSHOOTERID),
ShooterFollower(RIGHTSHOOTERID),
FeedMotor(FEEDMOTOR)
{
    ShooterController.ConfigFactoryDefault();
    ShooterFollower.ConfigFactoryDefault();
    ShooterController.SetNeutralMode(Coast);
    ShooterController.SetInverted(false);
    ShooterFollower.SetNeutralMode(Coast);
    ShooterFollower.SetInverted(true);

    ShooterController.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, kTimeoutMs);
    ShooterController.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    ShooterController.ConfigNominalOutputForward(0, kTimeoutMs);
    ShooterController.ConfigNominalOutputReverse(0, kTimeoutMs);
    ShooterController.ConfigPeakOutputForward(1, kTimeoutMs);
    ShooterController.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    ShooterController.Config_kF(kPIDLoopIdx, 0.1097, kTimeoutMs);
    ShooterController.Config_kP(kPIDLoopIdx, 0.3, kTimeoutMs);
    ShooterController.Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
    ShooterController.Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

    ShooterFollower.Follow(ShooterController);

}

void ShooterSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new DefaultShooterCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
