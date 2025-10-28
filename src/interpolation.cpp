#include "../include/interpolation.h"

double lagrange_interpolation(vector<double>& x, vector<double>& y, double xi) {
    int n = x.size();
    double result = 0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

double newton_interpolation(vector<double>& x, vector<double>& y, double xi) {
    int n = x.size();
    vector<vector<double>> divided_diff(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        divided_diff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            divided_diff[i][j] = (divided_diff[i + 1][j - 1] - divided_diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    double result = divided_diff[0][0];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (xi - x[i - 1]);
        result += divided_diff[0][i] * term;
    }

    return result;
}