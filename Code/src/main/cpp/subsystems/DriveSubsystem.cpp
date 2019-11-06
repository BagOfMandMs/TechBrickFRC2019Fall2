#include "subsystems/Subsystems.hpp"
#include "commands/Commands.hpp"
#include "ctre/Phoenix.h"

DriveSubsystem::DriveSubsystem()
    : frc::Subsystem("DriveSubsystem"), PitchMotor(PITCHMOTORID), LeftController(LEFTMOTORPRIMARYID), LeftFollower(LEFTMOTORSECONDARYID), RightController(RIGHTMOTORPRIMARYID), RightFollower(RIGHTMOTORSECONDARYID) {
        PitchMotor.SetInverted(false);
        PitchMotor.SetNeutralMode(Brake);
        LeftController.SetInverted(false);
        LeftController.SetNeutralMode(Brake);
        LeftFollower.SetInverted(false);
        LeftFollower.SetNeutralMode(Brake);
        LeftFollower.Follow(LeftController);
        RightController.SetInverted(false);
        RightController.SetNeutralMode(Brake);
        RightFollower.SetInverted(false);
        RightFollower.SetNeutralMode(Brake);
        RightFollower.Follow(RightController);
    }

void DriveSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new DefaultDriveCommand());
}