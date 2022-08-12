#include <cstdlib>
#include <iostream>
#include <cmath>
#include "ros/ros.h"
#include "uuv_gazebo_ros_plugins_msgs/FloatStamped.h"
#include <signal.h>

using namespace std;

uuv_gazebo_ros_plugins_msgs::FloatStamped velocityMessage;

void mySigintHandler(int sig);
double setRPM(ros::NodeHandle _node);


int main(int argc, char **argv)
{

  // Initiate ROS
  ros::init(argc, argv, "publish_velocity");

  // Create the main access point to communicate with ROS
  ros::NodeHandle node;

  signal(SIGINT, mySigintHandler);

  ros::Publisher velocityPub =
      node.advertise<uuv_gazebo_ros_plugins_msgs::FloatStamped>("lauv/thrusters/0/input", 0);

  // Specify a frequency that want the while loop below to loop at
  // Loop 10 cycles per second

  ros::Rate loop_rate(10);
  velocityMessage.data = setRPM(node);

  // Keep running the while loop below as long as the ROS Master is active.

  while (ros::ok())
  {

    velocityPub.publish(velocityMessage);
    ros::spin();

    loop_rate.sleep();
  }

  return 0;
}

double setRPM(ros::NodeHandle _node)
{

  double vel;
  double thrust;
  
  ROS_INFO("Node Started!");
  cout << "Enter The Desired Velocity: ";
  cin >> vel;

  if (vel == 0)
  {
    thrust = 0;
  }
  else
  {
    thrust = 6.916 * pow(vel, 3) - 38.796 * pow(vel, 2) + 175.211 * vel + 19.086; // Max Thrust 550
  }

  thrust > 550.0 ? thrust = 550.0 : thrust = thrust;
  thrust < -550.0 ? thrust = -550.0 : thrust = thrust;

  return -thrust;
}

void mySigintHandler(int sig)
{
  // Do some custom action.
  // For example, publish a stop message to some other nodes.

  // All the default sigint handler does is call shutdown()

  ROS_INFO("Node terminated !");

  ros::shutdown();
}