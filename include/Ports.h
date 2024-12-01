#include "pros/motor_group.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/imu.hpp"

// Ports.h
#ifndef PORTS_H
#define PORTS_H

// Declarations for functions, classes, and objects from Ports.cpp

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::ADIDigitalOut pneuSolenoid;
extern pros::Motor Intake;
extern pros::Motor Conveyer;
extern pros::Controller Controller;
extern pros::Imu imu;

#endif // PORTS_H
