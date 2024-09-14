#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/imu.hpp"

// Ports.h
#ifndef PORTS_H
#define PORTS_H

// Declarations for functions, classes, and objects from Ports.cpp

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::Motor Snapper;
extern pros::Motor Intake;
extern pros::Controller Controller;
extern pros::Imu imu;

// Add other necessary declarations here

#endif // PORTS_H
