#ifndef _PID_CNT_H_
#define _PID_CNT_H_

#include <math.h>
#include <ros/ros.h>

class Pid_Cnt
{
    public:
        Pid_Cnt(double dt, double max, double min, double Kp, double Kd, double Ki);
        ~Pid_Cnt();
        double calculate(const double setpoint, const double act_Val);

    private:
        double _dt;
        double _max;
        double _min;
        double _Kp;
        double _Kd;
        double _Ki;
        double _pre_error;
        double _integral;
};      

#endif