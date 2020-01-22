#include "subsystems/Subsystems.hpp"
#include "commands/Commands.hpp"
#include "ctre/Phoenix.h"

DriveSubsystem::DriveSubsystem()
    : frc::Subsystem("DriveSubsystem"), LeftController(LEFTMOTORPRIMARYID), LeftFollower(LEFTMOTORSECONDARYID), RightController(RIGHTMOTORPRIMARYID), RightFollower(RIGHTMOTORSECONDARYID) {
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

        table = NetworkTableInstance::GetTable("limelight");
        
    }

void DriveSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new DefaultDriveCommand());
}