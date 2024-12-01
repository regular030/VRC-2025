#include "Include.cpp"
#include "LemLibConfig.h"
#include "lemlib/chassis/trackingWheel.hpp"

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive,
                              &rightDrive,
                              13, 
                              lemlib::Omniwheel::NEW_4, 
                              300,
                              2 
);

// odometry settings
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to null
                            nullptr, // horizontal tracking wheel 1, set to null
                            nullptr, // horizontal tracking wheel 2, set to null
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(0, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20  // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(0, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)   
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors

);
