#include "ros/ros.h"
#include <math.h>
#include "auv_control_library/quaternion2euler.h"


double *quaternion2euler::getEuler()
{
  return euler;
}

void quaternion2euler::setEuler(double *euler){
  *this->euler = *euler;
}

void quaternion2euler::transform2euler(double x, double y, double z, double w)
{
  double t0, t1, t2, t3, t4 = 0;

  t0 = +2.0 * (w * x + y * z);
  t1 = +1.0 - 2.0 * (x * x + y * y);

  this->euler[0] = atan2(t0, t1);               //Roll

  t2 = +2.0 * (w * y - z * x);

  t2 > 1 ? t2 = 1 : t2 = t2;
  t2 < -1 ? t2 = -1 : t2 = t2;

  this->euler[1] = asin(t2);                    //Pitch

  t3 = +2.0 * (w * z + x * y);
  t4 = +1.0 - 2.0 * (y * y + z * z);

  this->euler[2] = atan2(t3, t4);               //Yaw

  // ROS_INFO("Orientation-> roll: [%f], pitch: [%f], yaw: [%f]", this->euler[0], this->euler[1], this->euler[2]);
}


