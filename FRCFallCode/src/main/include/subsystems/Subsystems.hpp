/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "RobotMap.hpp"
#include "ctre/Phoenix.h"

#include <frc/controller/PIDController.h>

class DriveSubsystem : public frc::Subsystem {
    public:
        DriveSubsystem();
        void InitDefaultCommand() override;
        TalonSRX RightController;
        TalonSRX RightFollower;
        TalonSRX LeftController;
        TalonSRX LeftFollower;
        std::shared_ptr<NetworkTable> table;
        float lastValue = 0;
        float integral = 0;
    private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
};

class ShooterSubsystem : public frc::Subsystem {
    public:
        ShooterSubsystem();
        void InitDefaultCommand() override;
        TalonSRX ShooterController;
        TalonSRX ShooterFollower;
        TalonSRX FeedMotor;
    private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
};

class ClimbSubsystem : public frc::Subsystem {
    public:
        ClimbSubsystem();
        void InitDefaultCommand() override;
        TalonSRX climbController;
        TalonSRX climbFollower;
        TalonSRX liftMotor;
        float runningCurrent;
    private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
};
