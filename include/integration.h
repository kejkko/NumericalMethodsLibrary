#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <functional>
using namespace std;

double rectangle_method(function<double(double)> f, double a, double b, int n);
double trapezoidal_method(function<double(double)> f, double a, double b, int n);
double simpson_method(function<double(double)> f, double a, double b, int n);
double gauss_legendre_2(function<double(double)> f, double a, double b);
double gauss_legendre_3(function<double(double)> f, double a, double b);
double gauss_legendre_4(function<double(double)> f, double a, double b);

#endif