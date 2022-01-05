#ifndef SIMPLE_PUBLISHER_H_
#define SIMPLE_PUBLISHER_H_
#include "ros/ros.h"
#include "rosstart/mystr.h"
#include<string>
namespace custom {
class SimplePublisher {
	public:
		SimplePublisher(const ros::NodeHandle &nh);
		void timer_callback(const ros::TimerEvent &event);
	private:
		ros::NodeHandle nh_;
		ros::Publisher pub1_;
		ros::Timer timer_;
		int count=0; // To keep count on the number of messages published on the topic
};
} // end of custom namespace
#endif  // SIMPLE_PUBLISHER_H_

