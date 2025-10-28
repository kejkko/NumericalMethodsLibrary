#include "../include/linear_systems.h"
#include "../include/interpolation.h"
#include "../include/integration.h"
#include <iostream>
#include <vector>

int main() {
    vector<vector<double>> A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    vector<double> b = {8, -11, -3};
    vector<double> x = gauss_elimination(A, b);
    
    cout << "Rozwiązanie układu równań:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    
    vector<double> px = {0, 1, 2, 3};
    vector<double> py = {1, 2, 5, 10};
    double interp_val = lagrange_interpolation(px, py, 1.5);
    cout << "Interpolacja Lagrange'a w punkcie 1.5: " << interp_val << endl;
    
    auto f = [](double x) { return x * x; };
    double integral = simpson_method(f, 0, 2, 1000);
    cout << "Całka z x^2 od 0 do 2: " << integral << endl;
    
    return 0;
}