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
                  
          static int i = 0; 
          i++; 
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 4, ("The i value is " + std::to_string(i)).c_str());
        }
        pros::delay(100);
  });
}

void disabled() {}

void competition_initialize() {}

//PLEASE COMMENT THIS SOON 

void red(){
  //code not final 
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(0, 22, 5000, {.forwards = false});
    Snapper.move_velocity(200);
    pros::delay(2000);
    Snapper.move_velocity(0);
    Intake.move_velocity(200);
    chassis.moveToPose(31, 27, -90, 5000);


}
void blue(){
  //testing....
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(0, 32, 5000, {.forwards = false});
    Snapper.move_velocity(200);
    pros::delay(2000);
    Snapper.move_velocity(0);
    Intake.move_velocity(200);
    chassis.moveToPoint(24, 36, 5000);
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
