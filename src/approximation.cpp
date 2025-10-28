#include "../include/approximation.h"
#include "../include/linear_systems.h"
#include <cmath>

vector<double> least_squares_approximation(vector<double>& x, vector<double>& y, int degree) {
    int n = x.size();
    int m = degree + 1;
    
    vector<vector<double>> A(m, vector<double>(m, 0));
    vector<double> b(m, 0);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                A[i][j] += pow(x[k], i + j);
            }
        }
        for (int k = 0; k < n; k++) {
            b[i] += y[k] * pow(x[k], i);
        }
    }
    
    return gauss_elimination(A, b);
}