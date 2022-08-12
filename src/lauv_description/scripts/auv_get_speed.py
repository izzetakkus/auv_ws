#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
import rospy
from geometry_msgs.msg import *
from nav_msgs.msg import Odometry

roll = pitch = yaw = 0.0

def get_speed(msg):
    global  v_x, v_y, v_z
    (v_x,v_y,v_z) = [msg.twist.twist.linear.x, msg.twist.twist.linear.y, msg.twist.twist.linear.z]

    rospy.sleep(0.3)

    print("x axis speed = %.2f  y axis speed= %.2f z axis speed = %.2f"%(v_y, v_x, v_z))


rospy.init_node('auv_speed_subscriber')

position_topic = '/lauv/pose_gt'
pose_subscriber = rospy.Subscriber(position_topic,Odometry,get_speed)

r = rospy.Rate(1)
while not rospy.is_shutdown():
    r.sleep()