#include "rosstart/SimplePublisher.hpp"
namespace custom{
	// initialize the class member nh_ with method argument nh
	SimplePublisher::SimplePublisher(const ros::NodeHandle &nh): nh_(nh){ 
		// Advertise publisher for rosmaster nh_.advertise<msg_type> ("topic name",buffer size)
		SimplePublisher::pub1_= nh_.advertise<rosstart::mystr>("/chat_oops",1000);
		// Create timer object to control frequency of publishing of message
		timer_ = nh_.createTimer(ros::Duration(0.1),&SimplePublisher::timer_callback,this);
		// Using message callback class_name::callback_fn, this
	}
	void SimplePublisher::timer_callback(const ros::TimerEvent &event){
		// Filling the message
		rosstart::mystr msg1;
		std::string str1= "hello_msg";
		msg1.name=str1;
		msg1.val =SimplePublisher::count;
		SimplePublisher::pub1_.publish(msg1);
		// For logging and info purposes
		ROS_INFO("%s : message published %ld times",msg1.name.c_str(), msg1.val);
		// count increment
		SimplePublisher::count++;
	}
} // end of namespace custom
