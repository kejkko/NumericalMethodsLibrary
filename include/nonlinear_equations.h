#ifndef NONLINEAR_EQUATIONS_H
#define NONLINEAR_EQUATIONS_H
#include <functional>
using namespace std;

double newton_method(function<double(double)> f, function<double(double)> df, double x0, double tol, int max_iter);
double secant_method(function<double(double)> f, double x0, double x1, double tol, int max_iter);
double bisection_method(function<double(double)> f, double a, double b, double tol, int max_iter);

#endif