// LemLibConfig.h
#ifndef LEMLIBCONFIG_H
#define LEMLIBCONFIG_H
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/chassis/chassis.hpp"

// Declare external encoders and tracking wheels
extern pros::Rotation horizontal_encoder;
extern pros::adi::Encoder vertical_encoder;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;

// Declare drivetrain settings
extern lemlib::Drivetrain drivetrain;

// Declare odometry settings
extern lemlib::OdomSensors sensors;

// Declare lateral PID controller settings
extern lemlib::ControllerSettings lateral_controller;

// Declare angular PID controller settings
extern lemlib::ControllerSettings angular_controller;

// Declare chassis object
extern lemlib::Chassis chassis;

#endif // LEMLIBCONFIG_H