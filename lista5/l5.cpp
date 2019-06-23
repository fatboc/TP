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

void param::setw(double x, double y, double z){
    w[0]=x;
    w[1]=y;
    w[2]=z;
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

    f[0] = (-1*c.k)/c.mass * sqrt((y[0]-c.w[0])*(y[0]-c.w[0]) + (y[1]-c.w[1])*(y[1]-c.w[1]) + (y[2]-c.w[2])*(y[2]-c.w[2])) * (y[0]-c.w[0])+g[0];
    f[1] = (-1*c.k)/c.mass * sqrt((y[0]-c.w[0])*(y[0]-c.w[0]) + (y[1]-c.w[1])*(y[1]-c.w[1]) + (y[2]-c.w[2])*(y[2]-c.w[2])) * (y[1]-c.w[1]) +g[1];
    f[2] = (-1*c.k)/c.mass* sqrt((y[0]-c.w[0])*(y[0]-c.w[0]) + (y[1]-c.w[1])*(y[1]-c.w[1]) + (y[2]-c.w[2])*(y[2]-c.w[2])) * (y[2]-c.w[2]) +g[2];
    f[3] = y[0];
    f[4] = y[1];
    f[5] = y[2];

    return GSL_SUCCESS;
}

void param::setpoints(){

    coeffs cf;
    cf.k = k0;
    cf.mass = mass;
    cf.w = w;

    int k=0;

    gsl_odeiv2_system sys = {func, NULL, 6, &cf};
    gsl_odeiv2_driver *d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-4, 1e-4, 0.0);

        double y[6] = {v_0[0], v_0[1], v_0[2], r_0[0], r_0[1], r_0[2]};
        double t=t_min;

        for (double j=t_min; j<t_max; j+=t_step){

            int status = gsl_odeiv2_driver_apply(d, &t, j, y);

            if(status!=GSL_SUCCESS){
                cout << "error " << status;
                break;
            }

                motion m;
                m.time = j;
                points.push_back(m);

            points[k].r={y[3], y[4], y[5]};
            points[k].v={y[0], y[1], y[2]};

            k++;
        }
        gsl_odeiv2_driver_free (d);


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

void param::set_init_val(){
    cout << "Podaj czas poczatkowy:" << endl;
    cin >> t_min;
    cout << "Podaj czas koncowy:" << endl;
    cin >> t_max;
    cout << "Podaj krok:" << endl;
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
    cout << "Podaj x-wspolrzadna predkosci wiatru: " << endl;
    cin >> w[0];
    cout << "Podaj y-wspolrzadna predkosci wiatru: " << endl;
    cin >> w[1];
    cout << "Podaj z-wspolrzadna predkosci wiatru: " << endl;
    cin >> w[2];
    cout << "Podaj wspolczynnik k:" << endl;
    cin >> k0;
    cout << "Podaj mase obiektu:" << endl;
    cin >> mass;


}
