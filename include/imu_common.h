#ifndef IMU_COMMON
#define IMU_COMMON

//所以平时需要用到的头文件都放在这里
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <typeinfo>
#include <inttypes.h>

#include <cmath>
#include <cstring>
#include <signal.h>
#include <sstream>
#include <vector>


#include "serial/serial.h"


//ros头文件
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Imu.h"

//常量定义
const float PI = 3.1415926;
const float g = 9.8;

using namespace std;
using namespace serial;



#endif // IMU_COMMON