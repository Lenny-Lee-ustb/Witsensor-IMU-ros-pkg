#include "ImuController.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "imu_node");
    ImuController  handle = ImuController();
    return 0;
}