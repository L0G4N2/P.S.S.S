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
    chassis.left_swing_to_angle(chassis.get_absolute_heading() + 1, 11, 2, 0, 1000, 2, 0, 7, 0);
    chassis.left_swing_to_angle(chassis.get_absolute_heading() - 1, 11, 2, 0, 1000, 2, 0, 7, 0);
  }
}

void gripRing(int numToGrip) {
  for (int i = 0; i <= numToGrip; i++) {
    chassis.drive_distance(2);
    wait(20, msec);
  }
}

// void motorPID(int angle) {
//   int desiredAngle = angle;
//   PID turnPID(reduce_negative_180_to_180(angle - get_absolute_heading()), turn_kp, turn_ki, turn_kd, turn_starti, turn_settle_error, turn_settle_time, turn_timeout);
//   while(turnPID.is_settled() == false){
//     float error = reduce_negative_180_to_180(angle - get_absolute_heading());
//     float output = turnPID.compute(error);
//     output = clamp(output, -turn_max_voltage, turn_max_voltage);
//     drive_with_voltage(output, -output);
//     task::sleep(10);
//   }
//   DriveL.stop(hold);
//   DriveR.stop(hold);
// }
 
void Red_Right(){
  // five
  Clamp.set(true);
  Doinker.set(true);
  // original distance for diagonal: -26
  chassis.drive_distance(-18, 0, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(false);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  // original angle to turn to -90 degrees: -60
  chassis.turn_to_angle(-90, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14, -90, 5, 2, 2, 0, 10000, 2, 00, 7, 0, 2, 0, 7, 0);
  gripRing(2);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  Intake.stop();
  Clamp.set(true);
  // original angle to turn to 0 degrees: 30
  chassis.turn_to_angle(0, 6, 2, 0, 2000, 2, 0, 7, 0);
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
  // original distance for diagonal: -26
  chassis.drive_distance(-18, 0, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // chassis.drive_distance(-8, -20, 5, 0, 2, 0, 1000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(2000, msec);
  Intake.spin(reverse);
  scorePoint();
  // original angle to turn to 90 degrees: 50
  chassis.turn_to_angle(90, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14, 90, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  // original angle to turn to 180 degrees: 140
  chassis.turn_to_angle(180, 6, 2, 0, 2000, 2, 0, 7, 0);
  Intake.stop();
}

void Blue_Right(){
  //Win point
  // original distance for diagonal: -26
  chassis.drive_distance(-18, 0, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  // chassis.drive_distance(-8, -20, 5, 0, 2, 0, 1000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(2000, msec);
  Intake.spin(reverse);
  scorePoint();
  // original angle to turn to 90 degrees: -50
  chassis.turn_to_angle(-90, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14, -90, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  // original angle to turn to 180 degrees: -140
  chassis.turn_to_angle(180, 6, 2, 0, 2000, 2, 0, 7, 0);
  Intake.stop();
}

void Blue_Left(){
  // six
  Clamp.set(false);
  Doinker.set(true);
  // original distance for diagonal: -26
  chassis.drive_distance(-18, 0, 5, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1500, msec);
  Intake.spin(reverse);
  scorePoint();
  // original angle to turn to 90 degrees: 60
  chassis.turn_to_angle(90, 6, 2, 0, 2000, 2, 0, 7, 0);
  chassis.drive_distance(14, 90, 5, 2, 2, 0, 10000, 2, 00, 7, 0, 2, 0, 7, 0);
  gripRing(2);
  Intake.spin(forward);
  gripRing(10);
  wait(1800, msec);
  scorePoint();
  Intake.stop();
  Clamp.set(false);
  // original angle to turn to 0 degrees: -30
  chassis.turn_to_angle(0, 6, 2, 0, 2000, 2, 0, 7, 0);
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
  // Clamp Goal and Score
  Clamp.set(false);
  chassis.drive_distance(-14, 0, 3, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  Intake.spin(forward);
  wait(1000, msec);
  // Score Two Rings in a Row
  chassis.turn_to_angle(-90, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(25, -90, 9, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  chassis.drive_distance(11, -90, 9, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Turn to Score the Ring Next to the Wall
  chassis.turn_to_angle(45, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(18, 42, 9, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Drive to Score the Ring in Line to the Robots Current Position
  chassis.turn_to_angle(-173, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(33, 180, 9, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Score the Ring Next to the Ladder
  chassis.turn_to_angle(87, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(24, 87, 9, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Drive and Drop Off the Goal in the Corner
  chassis.turn_to_angle(135, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(-50, 135, 11, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(false);
  /*
  // Drive to Clamp the Goal Across the Field
  chassis.turn_to_angle(-89, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(-64, -88, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(250, msec);
  chassis.turn_to_angle(-60, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(-18, -60, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(true);
  wait(250, msec);
  // Score the Two Rings in a Row
  chassis.turn_to_angle(90, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(25, 90, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  chassis.drive_distance(11, 90, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Turn to Score the Ring Next to the Wall
  chassis.turn_to_angle(-45, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(18, -45, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(1300, msec);
  // Score the Ring in Line to the Robots Current Position
  chassis.turn_to_angle(180, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(35, 180, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(250, msec);
  // Score the Ring Next to the Ladder
  chassis.turn_to_angle(-88, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(24, -88, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  wait(250, msec);
  // Drive and Drop Off the Goal in the Corner
  chassis.turn_to_angle(-135, 9, 2, 0, 2000, 2, 0, 7, 0);
  wait(250, msec);
  chassis.drive_distance(-90, -135, 10, 2, 2, 0, 10000, 2, 0, 7, 0, 2, 0, 7, 0);
  Clamp.set(false);
  */
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