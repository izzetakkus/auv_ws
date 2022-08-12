#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import *
from uuv_gazebo_ros_plugins_msgs.msg import FloatStamped

def getRPM():  
        rpm = int(input("Enter thruster RPM: "))
        return rpm

def publish_thrust(velocity_publisher,thrust):
    
    loop_rate = rospy.Rate(10)
    velocity_message = FloatStamped()

    while (True):

        velocity_message.data = thrust

        velocity_publisher.publish(velocity_message)

        loop_rate.sleep()
                

if __name__ == '__main__' :
    try:
        rospy.init_node('publish_thrust_mode',anonymous= True)
        #declare velocity publisher 

        thrusters_topic = '/lauv/thrusters/0/input'
        velocity_publisher = rospy.Publisher(thrusters_topic,FloatStamped,queue_size=10)

        publish_thrust(velocity_publisher,getRPM())

    except rospy.ROSInterruptException:
        rospy.loginfo("node terminated.")

