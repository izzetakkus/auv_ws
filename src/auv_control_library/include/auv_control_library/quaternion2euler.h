#ifndef QUATERNION2EULER_H 
#define QUATERNION2EULER_H

#include "ros/ros.h"

class quaternion2euler
{
private:
  double euler[3];

public:
  double *getEuler();
  void setEuler(double *euler);

  void transform2euler(double x, double y, double z, double w);
};


#endif // QUATERNION2EULER_H