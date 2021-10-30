cmake_minimum_required(VERSION 2.8.3)
project(wt931)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  serial
)

catkin_package()

