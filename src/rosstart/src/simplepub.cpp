#include "ros/ros.h"
#include "rosstart/mystr.h"
#include<string>
int main(int argc, char *argv[])
{
	ros::init(argc,argv,"pub_node");
	ros::NodeHandle n1;
	ros::Publisher pub1= n1.advertise<rosstart::mystr>("chat", 1000);
	ros::Rate loop_rate(10);
	int count=0;
	while (ros::ok())
	{
		rosstart::mystr msg1;
		std::string str1= "hello msg";
		msg1.name = str1;
		msg1.val = count;
		ROS_INFO("%s published with id %ld",msg1.name.c_str(), msg1.val);
		pub1.publish(msg1);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}
