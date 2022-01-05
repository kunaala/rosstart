#include "rosstart/SimplePublisher.hpp"
int main(int argc, char *argv[]){
	ros::init(argc,argv,"oops_pub_node");
	ros::NodeHandle nh;
	custom::SimplePublisher simple_pub(nh);
	ros::spin();
	return 0;
}
