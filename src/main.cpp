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
}