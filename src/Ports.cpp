#include "Ports.h"
#include "pros/imu.hpp"

//used
pros::MotorGroup rightDrive({-18, -15});
pros::MotorGroup leftDrive({-20, -19});

pros::Motor Intake(14);
pros::Motor Snapper(11);

pros::Imu imu(17);

pros::Controller Controller(pros::E_CONTROLLER_MASTER);
