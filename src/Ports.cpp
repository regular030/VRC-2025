#include "Ports.h"
#include "pros/imu.hpp"

//not used
pros::Motor DriveLF(13);
pros::Motor DriveLB(17);
pros::Motor DriveRF(16);
pros::Motor DriveRB(12);

//used
pros::MotorGroup leftDrive({-13, -17});
pros::MotorGroup rightDrive({-16, -12});

pros::Motor Intake(14);
pros::Motor Snapper(11);

pros::Imu imu(10);

pros::Controller Controller(pros::E_CONTROLLER_MASTER);