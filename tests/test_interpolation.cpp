#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "../include/interpolation.h"

using std::vector;

TEST(InterpolationTest, LagrangeInterpolation_Simple) {
    vector<double> x = {0, 1, 2};
    vector<double> y = {1, 2, 5};
    double result = lagrange_interpolation(x, y, 1.5);
    EXPECT_NEAR(result, 3.25, 1e-10);
}

TEST(InterpolationTest, LagrangeInterpolation_Quadratic) {
    vector<double> x = {1, 2, 3};
    vector<double> y = {1, 4, 9};
    double result = lagrange_interpolation(x, y, 2.5);
    EXPECT_NEAR(result, 6.25, 1e-10);
}

TEST(InterpolationTest, NewtonInterpolation_Simple) {
    vector<double> x = {0, 1, 2};
    vector<double> y = {1, 2, 5};
    double result = newton_interpolation(x, y, 1.5);
    EXPECT_NEAR(result, 3.25, 1e-10);
}

TEST(InterpolationTest, NewtonInterpolation_Quadratic) {
    vector<double> x = {1, 2, 3};
    vector<double> y = {1, 4, 9};
    double result = newton_interpolation(x, y, 2.5);
    EXPECT_NEAR(result, 6.25, 1e-10);
}
