#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void Red_Right();
void Red_Left();
void Blue_Right();
void Blue_Left();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();