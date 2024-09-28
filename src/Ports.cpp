#include "Ports.h"
#include "pros/imu.hpp"

//not used
pros::Motor DriveLF(13);
pros::Motor DriveLB(17);
pros::Motor DriveRF(16);
pros::Motor DriveRB(12);

//used
pros::MotorGroup rightDrive({-13, -15});
pros::MotorGroup leftDrive({-20, -19});

pros::Motor Intake(14);
pros::Motor Snapper(11);

pros::Imu imu(17);

pros::Controller Controller(pros::E_CONTROLLER_MASTER);