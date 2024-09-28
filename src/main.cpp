#include "Include.cpp"
#include "AwpRedLeft.cpp"
void initialize() {
    chassis.calibrate();

    pros::Task screenTask([]() {
    const int calibrationTime = 5000; // Set a threshold for calibration time in milliseconds
    int calibrationStartTime = pros::millis();

    while (true) {
          // Print robot location to the screen
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 1, "X: %f", chassis.getPose().x); // x
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 2, "Y: %f", chassis.getPose().y); // y
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 3, "Theta: %f", chassis.getPose().theta); // heading
                  
          // Increment and print i
          static int i = 0;  // make 'i' static to persist between loops
          i++;  // increment i
          pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, 4, ("The i value is " + std::to_string(i)).c_str());
        }
        pros::delay(100); // Delay to save resources (100ms)
  });
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 100000);
}