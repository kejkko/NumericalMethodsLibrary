#ifndef DIFFERENTIAL_EQUATIONS_H
#define DIFFERENTIAL_EQUATIONS_H
#include <vector>
#include <functional>
using namespace std;

vector<double> euler_method(function<double(double, double)> f, double x0, double y0, double h, int n);
vector<double> heun_method(function<double(double, double)> f, double x0, double y0, double h, int n);
vector<double> midpoint_method(function<double(double, double)> f, double x0, double y0, double h, int n);
vector<double> runge_kutta_4(function<double(double, double)> f, double x0, double y0, double h, int n);

#endif