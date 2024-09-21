#include "Include.cpp"
#include "UserControl.h"

// Function for driving on "Left Stick"
void Drive() {
  // get left y and right x positions
  int leftY = -1*Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int leftX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

  // move the robot
  chassis.arcade(leftX, leftY);
}

/* 
 * Function for snapper motor control on "A" button (forwards) and "Y" button (backwards)
*/
void Snapperr() {
  if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) { // Move Snapper motor forward
    Snapper.move_velocity(200);
  } else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) { // Move Snapper motor backwords
    Snapper.move_velocity(-200);
  } else{ // Stop the snapper
    Snapper.move_velocity(0); 
  }
}

// Function for intake motor control on "R1" (intake) and "R2" (outtake)
void Intaking() {
  if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    Intake.move_velocity(30); // Forward
  } else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    Intake.move_velocity(-30); // Backward
  } else {
    Intake.move_velocity(0); // Stop
  }
}

// Function for operator control 
void opcontrol() {
  Snapper.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

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
