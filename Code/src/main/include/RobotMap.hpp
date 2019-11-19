/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

constexpr int DATA0 = 0;
constexpr int DATA1 = 1;

constexpr int PITCHMOTORID = 02;
constexpr int LEFTMOTORPRIMARYID = 12;
constexpr int LEFTMOTORSECONDARYID = 13;
constexpr int RIGHTMOTORPRIMARYID = 14;
constexpr int RIGHTMOTORSECONDARYID = 15;

constexpr int DRIVEAXISX = 0;
constexpr int DRIVEAXISY = 1;
constexpr int DRIVEAXISZ = 2;

constexpr double TURNINGDEADBAND = .05;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
