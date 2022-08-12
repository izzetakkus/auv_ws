#include "auv_control_library/pid_cnt.h"

Pid_Cnt::Pid_Cnt( double dt, double max, double min, double Kp, double Kd, double Ki):
    _dt(dt),
    _max(max),
    _min(min),
    _Kp(Kp),
    _Kd(Kd),
    _Ki(Ki),
    _pre_error(0),
    _integral(0)
{
}

double Pid_Cnt::calculate(const double setpoint, const double act_Val)
{
    // Calculate error
    double error = setpoint - act_Val;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * _dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Restrict to max/min
    if( output > _max)
        output = _max;
    else if( output < _min)
        output = _min;
        
    // Anti windup
    else  
        _integral = Iout;

    // Save error to previous error
    _pre_error = error;

    ROS_INFO("control input: [%f]", output);

    return output;
}

Pid_Cnt::~Pid_Cnt()
{
    
}
