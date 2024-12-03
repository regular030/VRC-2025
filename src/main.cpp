#include "Include.cpp"
#include "Auto.cpp"

void initialize() {
    chassis.calibrate();
    chassis.setPose(0, 0, 0);

    pros::Task screenTask([]() {
    const int calibrationTime = 5000;
    int calibrationStartTime = pros::millis();

    while (true) {
          // Print robot location to the screen
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 1, "X: %f", chassis.getPose().x); // x
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 2, "Y: %f", chassis.getPose().y); // y
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 3, "Theta: %f", chassis.getPose().theta); // heading
        }
        pros::delay(100);
  });
}

void disabled() {}

void competition_initialize() {}

//PLEASE COMMENT THIS SOON 

void red(){
  //code not final 

}
void blue(){
  //testing....
}

// void skills(){

// }

void autonomous() {
    rightDrive.move_velocity(200);
    leftDrive.move_velocity(200);
    pros::delay(2000);
    rightDrive.move_velocity(0);
    leftDrive.move_velocity(0);
    }
