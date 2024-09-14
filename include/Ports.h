#include "lemlib/api.hpp"
#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/gps.h"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

// Ports.h
#ifndef PORTS_H
#define PORTS_H

// Declarations for functions, classes, and objects from Ports.cpp

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::Motor Snapper;
extern pros::Motor Intake;
extern pros::Controller Controller;

// Add other necessary declarations here

#endif // PORTS_H
