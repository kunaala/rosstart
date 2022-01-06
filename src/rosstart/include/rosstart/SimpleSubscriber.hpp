#ifndef SIMPLE_SUBSCRIBER_H_
#define SIMPLE_SUBSCRIBER_H
#include "ros/ros.h"
#include "rosstart/mystr.h"
namespace custom {
	class SimpleSubscriber {
		public:
			SimpleSubscriber(const ros::NodeHandle &nh);
		private:
			ros::NodeHandle nh_;
			ros::Subscriber sub1_;
			void message_callback(const rosstart::mystr msg1);
			
	};
};//end of custom namespace
#endif //SIMPLE_SUBSCRIBER_H
