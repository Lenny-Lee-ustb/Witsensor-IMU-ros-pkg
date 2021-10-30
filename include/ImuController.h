#include "CJY901.h"


class ImuController
{
public:
	ImuController();
	virtual ~ImuController();
	void publishImu();

private:
	//ros交互
	ros::NodeHandle nh;
	ros::Publisher publisher;
	sensor_msgs::Imu msg;

	//发布话题名称
	string pub_topic_name;
	
	//ros系统时间
	ros::Time time_current;

	//串口交互
	Serial * serialPort;
	string serialport_name;
    int baudrate;
	string ID;

	//通信协议
	CJY901 * protocol;

	//串口数据
	uint8_t * rxBuffer;

};