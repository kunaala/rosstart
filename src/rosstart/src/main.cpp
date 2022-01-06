#include "rosstart/SimplePublisher.hpp"
#include "rosstart/SimpleSubscriber.hpp"
int main(int argc, char *argv[]){
	ros::init(argc,argv,"oops_pubsub_node");
	ros::NodeHandle nh;
	custom::SimplePublisher simple_pub(nh);
	custom::SimpleSubscriber simple_sub(nh);
	ros::spin();
	return 0;
}
