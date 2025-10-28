#include "../include/nonlinear_equations.h"
#include <cmath>

double newton_method(function<double(double)> f, function<double(double)> df, double x0, double tol, int max_iter) {
    double x = x0;
    
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        if (abs(fx) < tol) return x;
        
        double dfx = df(x);
        if (abs(dfx) < 1e-12) return x;
        
        x = x - fx / dfx;
    }
    
    return x;
}

double secant_method(function<double(double)> f, double x0, double x1, double tol, int max_iter) {
    for (int i = 0; i < max_iter; i++) {
        double f0 = f(x0);
        double f1 = f(x1);
        
        if (abs(f1) < tol) return x1;
        if (abs(f1 - f0) < 1e-12) return x1;
        
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        x1 = x2;
    }
    
    return x1;
}

double bisection_method(function<double(double)> f, double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) return (a + b) / 2;
    
    for (int i = 0; i < max_iter; i++) {
        double c = (a + b) / 2;
        double fc = f(c);
        
        if (abs(fc) < tol || (b - a) / 2 < tol) return c;
        
        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    return (a + b) / 2;
}