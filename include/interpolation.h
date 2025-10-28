#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include <vector>
using namespace std;

double lagrange_interpolation(vector<double>& x, vector<double>& y, double xi);
double newton_interpolation(vector<double>& x, vector<double>& y, double xi);

#endif