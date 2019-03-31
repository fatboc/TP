#include <iostream>
#include <vector>
#include <map>
#include <gsl/gsl_const_mksa.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>

using namespace std;

const vector<double> g = {0, 0, -1*GSL_CONST_MKSA_GRAV_ACCEL};

class motion;

class param{
    double t_min;
    double t_max;
    double t_step;

    vector<double> v_0 = {0, 0, 0};
    vector<double> r_0 = {0, 0, 0};

    vector<motion> points;

    public:
    param();
    param(double _min, double _max, double _step): t_min(_min), t_max(_max), t_step(_step){};
    void setpoints();
    void setv(double x, double y, double z);
    void setv(vector<double> v);
    void setr(double x, double y, double z);
    void setr(vector<double> r);
    void fprint();
};


class motion{
    double time;
    vector<double> v = {0, 0, 0};
    vector<double> r = {0, 0, 0};

    public:
    void print();
    void fprint();
    friend void param::setpoints();
};