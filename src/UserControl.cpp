#include "Include.cpp"
#include "UserControl.h"
#include "LemLibConfig.cpp"

// Function for driving on "Right Stick"
void Drive() {
  // Get R stick axis
  int forward = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Forward/backward on the right stick
  int turn = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y); // Turning on the right stick

  // Calculate motor speeds for arcade drive
  int leftSpeed = forward - turn;
  int rightSpeed = forward + turn;

  // Set motor speeds
  leftDrive.move(leftSpeed);
  rightDrive.move(rightSpeed);
}

/* 
 * Function for snapper motor control on "A" button (forwards) and "Y" button (backwards)
*/
void Snapperr() {
  if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) { // Move Snapper motor forward
    Snapper.move_velocity(200);
  } 
  else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) { // Move Snapper motor backwords
    Snapper.move_velocity(200);
  } 
  else{ // Stop the snapper
    Snapper.move_velocity(0); 
  }
}

// Function for intake motor control on "R1" (intake) and "R2" (outtake)
void Intaking() {
  if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    Intake.move_velocity(150); // Forward
  } else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    Intake.move_velocity(-150); // Backward
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
