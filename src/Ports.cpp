#include "Ports.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"

//used
pros::MotorGroup rightDrive({18, 15}, pros::MotorGearset::green);
pros::MotorGroup leftDrive({-20, -19}, pros::MotorGearset::green);

pros::Motor Intake(14, pros::MotorGearset::green);
pros::Motor Conveyer(11, pros::MotorGearset::blue);

pros::ADIDigitalOut pneuSolenoid(1);

pros::Imu imu(12);

pros::Controller Controller(pros::E_CONTROLLER_MASTER);
