/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/commands/Command.h>

class DefaultDriveCommand : public frc::Command {
   public:
    DefaultDriveCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class DefaultShooterCommand : public frc::Command {
   public:
    DefaultShooterCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class DefaultClimbCommand : public frc::Command {
   public:
    DefaultClimbCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class TrackCommand : public frc::Command {
   public:
    TrackCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class DebugCommand : public frc::Command {
   public:
    DebugCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ArmCommand : public frc::Command {
   public:
    ArmCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
class ClimbCommand : public frc::Command {
   public:
    ClimbCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
class LiftCommand : public frc::Command {
   public:
    LiftCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};