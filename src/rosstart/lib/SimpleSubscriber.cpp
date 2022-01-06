#include "rosstart/SimpleSubscriber.hpp"
namespace custom{
	// initialize the class member nh_ with method argument nh
	SimpleSubscriber::SimpleSubscriber(const ros::NodeHandle &nh) : nh_(nh){
		SimpleSubscriber::sub1_ = SimpleSubscriber::nh_.subscribe("/chat_oops",1000,&SimpleSubscriber::message_callback,this);
	}

	void SimpleSubscriber::message_callback( const rosstart::mystr msg1) {
		ROS_INFO("received message %s from publisher %ld times", msg1.name.c_str(), msg1.val);
	}
} // end of custom namespace
