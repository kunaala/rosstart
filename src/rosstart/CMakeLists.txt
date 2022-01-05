cmake_minimum_required(VERSION 2.8.3)
project(rosstart)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation roslib)

## Declare ROS messages and services
add_message_files(FILES mystr.msg)
# add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)


## Declare a catkin package

catkin_package(
	INCLUDE_DIRS include
	LIBRARIES simple_pub_core
	CATKIN_DEPENDS roscpp std_msgs message_runtime roslib
	)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(simple_pub_core
	lib/SimplePublisher.cpp
	)

target_link_libraries(simple_pub_core
  ${catkin_LIBRARIES}
	)

## Build talker and simple_pub

add_executable(talker src/simplepub.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker rosstart_generate_messages_cpp)

add_executable(simple_pub src/main.cpp)
# also link with  simple_pub_core user defined library 
target_link_libraries(simple_pub ${catkin_LIBRARIES} simple_pub_core)
add_dependencies(simple_pub rosstart_generate_messages_cpp)

# add_executable(listener src/listener.cpp)
# target_link_libraries(listener ${catkin_LIBRARIES})
# add_dependencies(listener beginner_tutorials_generate_messages_cpp)
