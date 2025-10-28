#include "../include/integration.h"
#include <cmath>

double rectangle_method(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

double trapezoidal_method(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2;
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

double simpson_method(function<double(double)> f, double a, double b, int n) {
    if (n % 2 == 1) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }
    
    return sum * h / 3;
}

double gauss_legendre_2(function<double(double)> f, double a, double b) {
    double c1 = 1.0, c2 = 1.0;
    double x1 = -1.0 / sqrt(3), x2 = 1.0 / sqrt(3);
    
    double t1 = (b - a) / 2 * x1 + (b + a) / 2;
    double t2 = (b - a) / 2 * x2 + (b + a) / 2;
    
    return (b - a) / 2 * (c1 * f(t1) + c2 * f(t2));
}

double gauss_legendre_3(function<double(double)> f, double a, double b) {
    double c1 = 5.0/9, c2 = 8.0/9, c3 = 5.0/9;
    double x1 = -sqrt(3.0/5), x2 = 0, x3 = sqrt(3.0/5);
    
    double t1 = (b - a) / 2 * x1 + (b + a) / 2;
    double t2 = (b - a) / 2 * x2 + (b + a) / 2;
    double t3 = (b - a) / 2 * x3 + (b + a) / 2;
    
    return (b - a) / 2 * (c1 * f(t1) + c2 * f(t2) + c3 * f(t3));
}

double gauss_legendre_4(function<double(double)> f, double a, double b) {
    double c1 = (18 - sqrt(30)) / 36, c2 = (18 + sqrt(30)) / 36;
    double c3 = c2, c4 = c1;
    double x1 = -sqrt(3.0/7 + 2.0/7 * sqrt(6.0/5));
    double x2 = -sqrt(3.0/7 - 2.0/7 * sqrt(6.0/5));
    double x3 = -x2, x4 = -x1;
    
    double t1 = (b - a) / 2 * x1 + (b + a) / 2;
    double t2 = (b - a) / 2 * x2 + (b + a) / 2;
    double t3 = (b - a) / 2 * x3 + (b + a) / 2;
    double t4 = (b - a) / 2 * x4 + (b + a) / 2;
    
    return (b - a) / 2 * (c1 * f(t1) + c2 * f(t2) + c3 * f(t3) + c4 * f(t4));
}