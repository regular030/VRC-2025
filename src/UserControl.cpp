#include "Include.cpp"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"
#include "UserControl.h"

// Function for driving on "Left Stick"
void Drive() {
  // get left y and right x positions
  int leftY = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int leftX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

  // move the robot
  chassis.arcade(leftY, leftX);
}

// Function for snapper pneumatics control with a single button toggle (A)
void Snapperr() {
  static bool pneuExtended = false;  // Tracks the current state of the solenoid

  if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    // Toggle the state
    pneuExtended = !pneuExtended;
    
    // Set the solenoid to the new state
    pneuSolenoid.set_value(pneuExtended);
  }
}

// Function for intake motor control on "R1" (intake) and "R2" (outtake)
void Intaking() {
  if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    Intake.move_velocity(200); // Forward
    Conveyer.move_velocity(600);
  } else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    Intake.move_velocity(-200); // Backward
    Conveyer.move_velocity(-600);
  } else {
    Intake.move_velocity(0); // Stop
    Conveyer.move_velocity(0);
  }
}

// Function for operator control 
void opcontrol() {
  // Creating tasks to run each function asynchronously
  pros::Task driveTask([] {
    while (true) {
      Drive();
      pros::delay(20);
    }
  });

  pros::Task snapperTask([] {
    while (true) {
      Snapperr();
      pros::delay(20); 
    }
  });

  pros::Task intakeTask([] {
    while (true) {
      Intaking();
      pros::delay(20);
    }
  });

  // Main control loop to keep tasks running
  while (true) {
    pros::delay(100); // Main loop delay
  }
}

