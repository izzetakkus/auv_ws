execute_process(COMMAND "/home/tbtk/auv_ws/build/uuv_trajectory_control/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/tbtk/auv_ws/build/uuv_trajectory_control/catkin_generated/python_distutils_install.sh) returned error code ")
endif()