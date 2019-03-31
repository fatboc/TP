#include "l5.h"
//
//double vel(double t, void * params){
//    double g = *(double *) params;
//    double v_0 = *(double *) (params+1);
//    double v = v_0 + g*t;
//
//    return v;
//}
//
//int func (double t, const double y[], double dydt[], void *params)
//{
//  (void)(t); /* avoid unused parameter warning */
//  double g = *(double *)params;
//  dydt[0] = y[1];
//  dydt[1] = g;
//  return GSL_SUCCESS;
//}
//
///*int jac (double t, const double y[], double *dfdy, double dfdt[], void *params)
//{
//  (void)(t); /* avoid unused parameter warning
//  double mu = *(double *)params;
//  gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
//  gsl_matrix * m = &dfdy_mat.matrix;
//  gsl_matrix_set (m, 0, 0, 0.0);
//  gsl_matrix_set (m, 0, 1, 1.0);
//  gsl_matrix_set (m, 1, 0, -2.0*mu*y[0]*y[1] - 1.0);
//  gsl_matrix_set (m, 1, 1, -mu*(y[0]*y[0] - 1.0));
//  dfdt[0] = 0.0;
//  dfdt[1] = 0.0;
//  return GSL_SUCCESS;
//}*/
//
//int * jac = NULL;
//
//vector<double> pos(double r_0, double v_0, double t, double g){
//
//    /*gsl_integration_workspace * w = gsl_integration_workspace_alloc (1000);
//
//    double result, error;
//    double alpha[2] = {g, v_0};
//
//    vector<double> res;
//
//    gsl_function F;
//    F.function = &vel;
//    F.params = &alpha;
//
//    for(int i=0; i<3; i++)
//        gsl_integration_qags (&F, 0, t, 0, 1e-7, 1000, w, &result, &error);
//
//    /*printf ("result          = % .18f\n", result);
//    printf ("estimated error = % .18f\n", error);
//    printf ("intervals       = %zu\n", w->size);
//
//    gsl_integration_workspace_free (w);
//
//    res.push_back(result + r_0);
//    res.push_back(vel(t, alpha));
//
//    return res;*/
//
//    vector<double> res;
//
//    int dim=2, i;
//    double * params = &g;
//    gsl_odeiv2_system sys = {func, NULL, dim, params};
//    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45, 1e-6, 1e-6, 0.0);
//    double x = 0.0, x_0 = x, x_k = 10.0;
//    double y[2] = {r_0, v_0};
//
//    for (i=1; i<100; i++){
//        double x_i = x_0 + i*(x_k - x_0) / 10.0;
//        int status = gsl_odeiv2_driver_apply(d, &x, x_i, y);
//
//        if (status!=GSL_SUCCESS){
//            cout << "error" << status;
//            break;
//        }
//
//        //cout << i << ": " << x << " " << y[0] << " "<< y[1] << endl;
//    }
//
//    gsl_odeiv2_driver_free(d);
//
//    res.push_back(y[0]);
//    res.push_back(y[1]);
//
//    return res;
//
//}
//
//void param::setpoints(){
//
//    for(double i=t_min; i<t_max; i+=t_step){
//        motion m;
//        m.time = i;
//
//        for(int j=0; j<3; j++){
//            vector<double> val = pos(r_0[i], v_0[i], m.time, g[i]);
//            m.r[i] = val[0];
//            m.v[i] = val[1];
//        }
//
//        points.push_back(m);
//        m.print();
//    }
//}


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

void motion::print(){
    cout << time << "; [";
    cout << r[0] << ", ";
    cout << r[1] << ", ";
    cout << r[2] << "]; [" << v[0] << ", " << v[1] << ", " << v[2] << "]; " << endl;
}

int func(double t, const double y[], double f[], void * params){
    (void)(t);
    double p = *(double*)params;

    f[0] = y[1];
    f[1] = p;

    return GSL_SUCCESS;
}

void param::setpoints(){
        int k=0;

    for(int i=0; i<3; i++){
        k=0;
        double g0=g[i];
        gsl_odeiv2_system sys = {func, NULL, 2, &g0};
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
