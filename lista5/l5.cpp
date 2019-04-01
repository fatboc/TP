#include "l5.h"

void param::setv(double x, double y, double z){
    v_0[0]=x;
    v_0[1]=y;
    v_0[2]=z;
}
void param::setr(double x, double y, double z){
    r_0[0]=x;
    r_0[1]=y;
    r_0[2]=z;
}

void param::setk(double _k){
    k0=_k;
}

void param::setm(double _m){
    mass=_m;
}

void motion::print(){
    cout << time << "; [";
    cout << r[0] << ", ";
    cout << r[1] << ", ";
    cout << r[2] << "]; [" << v[0] << ", " << v[1] << ", " << v[2] << "]; " << endl;
}

int func(double t, const double y[], double f[], void * params){
    (void)(t);
    coeffs c = *(coeffs*)params;
    double p = c.g;
    double k = c.k;
    double m = c.mass;

    //double alpha = k / m;

    f[0] = y[1];
    f[1] = p + (k/m)*y[1];

    cout << p << "; " << k << endl;

    return GSL_SUCCESS;
}

void param::setpoints(){
        int k=0;

        coeffs c;

    for(int i=0; i<3; i++){
        k=0;
        c.g = g[i];
        c.k = k0;
        c.mass = mass;

        gsl_odeiv2_system sys = {func, NULL, 2, &c};
        gsl_odeiv2_driver *d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-4, 1e-4, 0.0);

        double y[2] = {r_0[i], v_0[i]};
        double t=t_min;

        for (double j=t_min; j<t_max; j+=t_step){

            int status = gsl_odeiv2_driver_apply(d, &t, j, y);

            if(status!=GSL_SUCCESS){
                cout << "error " << status;
                break;
            }

            if(i==0){
                motion m;
                m.time = j;
                points.push_back(m);
            }

            points[k].r[i]=y[0];
            points[k].v[i]=y[1];

            k++;
        }
        gsl_odeiv2_driver_free (d);
    }

    for (int j=0; j<k; j++){
        points[j].print();
    }
}

void param::fprint(){
    ofstream out;
    out.open("wynik.csv");

    out << "TIME,POS_X,POS_Y,POS_Z,VEL_X,VEL_Y,VEL_Z" << endl;

    for(int i=0; i<points.size(); i++){
        out << points[i].time << ",";
        for(int j=0; j<3; j++)
            out << points[i].r[j] << ",";
        for(int j=0; j<3; j++)
            out << points[i].v[j] << ",";
        out << endl;
    }
}

void param::get_init_val(){
    cout << "Podaj czas poczatkowy" << endl;
    cin >> t_min;
    cout << "Podaj czas koncowy" << endl;
    cin >> t_max;
    cout << "Podaj krok" << endl;
    cin >> t_step;
    cout << "Podaj x-wspolrzadna polozenia poczatkowego: " << endl;
    cin >> r_0[0];
    cout << "Podaj y-wspolrzadna polozenia poczatkowego: " << endl;
    cin >> r_0[1];
    cout << "Podaj z-wspolrzadna polozenia poczatkowego: " << endl;
    cin >> r_0[2];
    cout << "Podaj x-wspolrzadna predkosci poczatkowej: " << endl;
    cin >> v_0[0];
    cout << "Podaj y-wspolrzadna predkosci poczatkowej: " << endl;
    cin >> v_0[1];
    cout << "Podaj z-wspolrzadna predkosci poczatkowej: " << endl;
    cin >> v_0[2];

}
