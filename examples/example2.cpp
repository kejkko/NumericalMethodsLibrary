#include "../include/differential_equations.h"
#include "../include/nonlinear_equations.h"
#include "../include/approximation.h"
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    auto f = [](double x, double y) { return -2 * y + x; };
    vector<double> solution = runge_kutta_4(f, 0, 1, 0.1, 10);
    
    cout << "Rozwiązanie równania różniczkowego:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "y(" << i * 0.1 << ") = " << solution[i] << endl;
    }
    
    auto g = [](double x) { return x * x - 4; };
    auto dg = [](double x) { return 2 * x; };
    double root = newton_method(g, dg, 1, 1e-10, 100);
    cout << "Pierwiastek równania x^2 - 4 = 0: " << root << endl;
    
    vector<double> x_data = {1, 2, 3, 4, 5};
    vector<double> y_data = {2.1, 3.9, 6.1, 7.9, 10.1};
    vector<double> coeffs = least_squares_approximation(x_data, y_data, 1);
    cout << "Aproksymacja liniowa: y = " << coeffs[0] << " + " << coeffs[1] << "x" << endl;
    
    return 0;
}