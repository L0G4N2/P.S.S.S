#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(12, .4, 0, 1, 0);
  chassis.set_turn_constants(8, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 2000);
  chassis.set_turn_exit_conditions(1, 000, 2000);
  chassis.set_swing_exit_conditions(1, 000, 2000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
}

void scorePoint() {
  for (int i = 0; i <= 3; i++) {
    chassis.left_swing_to_angle(chassis.get_absolute_heading() + 2, 10, 2, 0, 1000, 2, 0, 7, 0);
    chassis.left_swing_to_angle(chassis.get_absolute_heading() - 2, 10, 2, 0, 1000, 2, 0, 7, 0);
  }
}

void gripRing(int numToGrip) {
  for (int i = 0; i <= numToGrip; i++) {
    chassis.drive_distance(2);
  }
}

void Red_Right(){
  // five
  Clamp.set(false);
  chassis.drive_distance(-26, 0, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(-60, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  Intake.stop();
  Clamp.set(false);
  chassis.turn_to_angle(30, 6, 2, 0, 2000, 2, 0, 7, 0);
  // // distance to center right goal, change first value only, always keep negative
  // chassis.drive_distance(-12, 0, 4, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // Clamp.set(true);
  // wait(250, msec);
  // chassis.drive_distance(28, 0, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // chassis.turn_to_angle(60, 6, 2, 0, 2000, 2, 0, 7, 0);
  // chassis.drive_distance(-50, 60, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // Clamp.set(false);
  // Intake.stop();
}

void Red_Left(){
  // five
  chassis.drive_distance(-26);
  // chassis.drive_distance(-8, -20, 5, 0, 2, 0, 1000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(2000, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(50, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(13, 50, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  chassis.turn_to_angle(140, 6, 2, 0, 2000, 2, 0, 7, 0);
  Intake.stop();
}

void Blue_Right(){
  //Win point
  chassis.drive_distance(-26);
  // chassis.drive_distance(-8, -20, 5, 0, 2, 0, 1000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(2000, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(-50, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(13, -50, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  chassis.turn_to_angle(-140, 6, 2, 0, 2000, 2, 0, 7, 0);
  Intake.stop();
}

void Blue_Left(){
  // six
  Clamp.set(false);
  chassis.drive_distance(-26, 0, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(60, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  Intake.stop();
  Clamp.set(false);
  chassis.turn_to_angle(-30, 6, 2, 0, 2000, 2, 0, 7, 0);
  // // distance to center left goal, change first value only, always keep negative
  // chassis.drive_distance(-12, 0, 4, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // Clamp.set(true);
  // wait(250, msec);
  // chassis.drive_distance(28, 0, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // chassis.turn_to_angle(60, 6, 2, 0, 2000, 2, 0, 7, 0);
  // chassis.drive_distance(-50, -60, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // Clamp.set(false);
  // Intake.stop();
}

void Skills() {
  Clamp.set(false);
  // chassis.drive_distance(-8, -30, 5, 0);
  chassis.drive_distance(-8, 0, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  chassis.turn_to_angle(-60, 5, 2, 0, 2000, 2, 0, 7, 0);
  // chassis.drive_distance(15, 0, 10, 0);
  chassis.drive_distance(15, 30, 10, 3, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  gripRing(10);
  wait(2500, msec);
  chassis.turn_to_angle(-75, 10, 2, 0, 1200, 2, 0, 7, 0);
  chassis.drive_distance(15, -75, 8, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  gripRing(10);
  wait(2500, msec);
}

void full_test() {
  Brain.Screen.print("Super cool and awesome things :)");
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}