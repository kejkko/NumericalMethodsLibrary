#include "../include/differential_equations.h"

vector<double> euler_method(function<double(double, double)> f, double x0, double y0, double h, int n) {
    vector<double> y(n + 1);
    y[0] = y0;
    
    for (int i = 0; i < n; i++) {
        y[i + 1] = y[i] + h * f(x0 + i * h, y[i]);
    }
    
    return y;
}

vector<double> heun_method(function<double(double, double)> f, double x0, double y0, double h, int n) {
    vector<double> y(n + 1);
    y[0] = y0;
    
    for (int i = 0; i < n; i++) {
        double k1 = f(x0 + i * h, y[i]);
        double k2 = f(x0 + (i + 1) * h, y[i] + h * k1);
        y[i + 1] = y[i] + h / 2 * (k1 + k2);
    }
    
    return y;
}

vector<double> midpoint_method(function<double(double, double)> f, double x0, double y0, double h, int n) {
    vector<double> y(n + 1);
    y[0] = y0;
    
    for (int i = 0; i < n; i++) {
        double k1 = f(x0 + i * h, y[i]);
        double k2 = f(x0 + i * h + h / 2, y[i] + h / 2 * k1);
        y[i + 1] = y[i] + h * k2;
    }
    
    return y;
}

vector<double> runge_kutta_4(function<double(double, double)> f, double x0, double y0, double h, int n) {
    vector<double> y(n + 1);
    y[0] = y0;
    
    for (int i = 0; i < n; i++) {
        double k1 = f(x0 + i * h, y[i]);
        double k2 = f(x0 + i * h + h / 2, y[i] + h / 2 * k1);
        double k3 = f(x0 + i * h + h / 2, y[i] + h / 2 * k2);
        double k4 = f(x0 + (i + 1) * h, y[i] + h * k3);
        y[i + 1] = y[i] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
    }
    
    return y;
}