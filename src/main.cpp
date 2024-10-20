#include "Include.cpp"
#include "AwpRedLeft.cpp"
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

void autonomous() {
     // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // move 48" forwards
    chassis.moveToPoint(0, 48, 10000);
    // turn 90 deg
    chassis.turnToHeading(-90, 10000);
    // move 48" forwards
    chassis.moveToPoint(48, 48, 10000);
    chassis.turnToHeading(-90, 10000);


}