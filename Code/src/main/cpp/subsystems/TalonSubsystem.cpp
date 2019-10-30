#include "subsystems/Subsystems.hpp"

TalonSubsystem::TalonSubsystem()
    : frc::Subsystem("TalonSubsystem"), pitchMotor(PITCHMOTORID) {}

void TalonSubsystem::InitDefaultCommand() {}