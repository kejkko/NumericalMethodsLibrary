#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "../include/linear_systems.h"

using std::vector;

TEST(LinearSystemsTest, GaussElimination_3x3) {
    vector<vector<double>> A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    vector<double> b = {8, -11, -3};
    vector<double> x = gauss_elimination(A, b);
    EXPECT_NEAR(x[0], 2, 1e-10);
    EXPECT_NEAR(x[1], 3, 1e-10);
    EXPECT_NEAR(x[2], -1, 1e-10);
}

TEST(LinearSystemsTest, GaussElimination_2x2) {
    vector<vector<double>> A = {{1, 2}, {3, 4}};
    vector<double> b = {5, 6};
    vector<double> x = gauss_elimination(A, b);
    EXPECT_NEAR(x[0], -4, 1e-10);
    EXPECT_NEAR(x[1], 4.5, 1e-10);
}

TEST(LinearSystemsTest, LUDecomposition_3x3) {
    vector<vector<double>> A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    vector<double> b = {8, -11, -3};
    vector<double> x = lu_decomposition(A, b);
    EXPECT_NEAR(x[0], 2, 1e-10);
    EXPECT_NEAR(x[1], 3, 1e-10);
    EXPECT_NEAR(x[2], -1, 1e-10);
}

TEST(LinearSystemsTest, LUDecomposition_2x2) {
    vector<vector<double>> A = {{4, 3}, {6, 3}};
    vector<double> b = {10, 12};
    vector<double> x = lu_decomposition(A, b);
    EXPECT_NEAR(x[0], 1, 1e-10);
    EXPECT_NEAR(x[1], 2, 1e-10);
}
