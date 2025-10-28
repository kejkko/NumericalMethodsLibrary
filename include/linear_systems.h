#ifndef LINEAR_SYSTEMS_H
#define LINEAR_SYSTEMS_H
#include <vector>
using namespace std;

vector<double> gauss_elimination(vector<vector<double>>& A, vector<double>& b);
vector<double> lu_decomposition(vector<vector<double>>& A, vector<double>& b);

#endif