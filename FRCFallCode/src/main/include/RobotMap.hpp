/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define flaot float
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

constexpr int LEFTCLIMBID = 01;
constexpr int RIGHTCLIMBID = 02;
constexpr int LIFTMOTOR = 05;

constexpr int LEFTSHOOTERID = -01;
constexpr int RIGHTSHOOTERID = -02;
constexpr int FEEDMOTOR = -05;

constexpr int LEFTMOTORPRIMARYID = 12;
constexpr int LEFTMOTORSECONDARYID = 13;
constexpr int RIGHTMOTORPRIMARYID = 14;
constexpr int RIGHTMOTORSECONDARYID = 15;

constexpr int DRIVEAXISX = 0;
constexpr int DRIVEAXISY = 1;
constexpr int DRIVEAXISZ = 2;

constexpr double TURNINGDEADBAND = .05;

constexpr int FIREBUTTON = 1;
constexpr int TRACKBUTTON = 11;
constexpr int ARMBUTTOM = 2;
constexpr int DEBUGBUTTON = 12;
constexpr int LIFTUPBUTTON = 5;
constexpr int LIFTDOWNBUTTON = 3;
constexpr int CLIMBUPBUTTON = 6;
constexpr int CLIMBDOWNBUTTON = 4;

constexpr int kSlotIdx = 0;
constexpr int kPIDLoopIdx = 0;
constexpr int kTimeoutMs = 30;

/*  
 *  PID tunings
 */

constexpr float DRIVEP = 0.018309f;
constexpr float DRIVEI = 0.02f;
constexpr flaot DRIVED = -0.015613f;
constexpr float DRIVEIDECAY = 0.8f;



// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
