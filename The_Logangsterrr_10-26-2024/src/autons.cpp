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
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-20, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(-8);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  // chassis.drive_distance();
  chassis.turn_to_angle(-90, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(10);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  // // chassis.drive_distance(-2);
  Clamp.set(false);
  chassis.turn_to_angle(0, 10, 2, 0, 1000, 2, 0, 7, 0);
  // // // wait(500, msec);
  // chassis.drive_distance(-18);
  // Clamp.set(true);
  // // // wait(700, msec);
  // chassis.drive_distance(28);
  // chassis.turn_to_angle(60);
  // chassis.drive_distance(-50);
  Clamp.set(false);
  Intake.stop();
}

void Red_Left(){
  // five
  chassis.drive_distance(-18);
  chassis.turn_to_angle(20, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(-8);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(90, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(10);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  chassis.turn_to_angle(90, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(10);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
}

void Blue_Right(){
  //Win point
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-20, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(-8);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  chassis.turn_to_angle(-90, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(10);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
}

void Blue_Left(){
  // six
  Clamp.set(false);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(20, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(-8);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  // chassis.drive_distance();
  chassis.turn_to_angle(90, 10, 2, 0, 1000, 2, 0, 7, 0);
  chassis.drive_distance(10);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  //26haydenwyble@onalaskaisd.net
  // // chassis.drive_distance(-2);
  Clamp.set(false);
  chassis.turn_to_angle(0, 10, 2, 0, 1000, 2, 0, 7, 0);
  // // // wait(500, msec);
  // chassis.drive_distance(-18);
  // Clamp.set(true);
  // // // wait(700, msec);
  // chassis.drive_distance(28);
  // chassis.turn_to_angle(60);
  // chassis.drive_distance(-50);
  Clamp.set(false);
  Intake.stop();
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