#include <gtest/gtest.h>
#include "../include/approximation.h"
#include <cmath>

TEST(ApproximationTest, LinearFit) {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {1, 2, 3, 4};
    std::vector<double> coeffs = least_squares_approximation(x, y, 1);

    ASSERT_EQ(coeffs.size(), 2);
    EXPECT_NEAR(coeffs[0], 1.0, 1e-10);  // wyraz wolny
    EXPECT_NEAR(coeffs[1], 1.0, 1e-10);  // współczynnik kierunkowy
}

TEST(ApproximationTest, QuadraticFit) {
    std::vector<double> x = {1, 2, 3};
    std::vector<double> y = {1, 4, 9};
    std::vector<double> coeffs = least_squares_approximation(x, y, 2);

    ASSERT_EQ(coeffs.size(), 3);
    EXPECT_NEAR(coeffs[2], 1.0, 1e-10);  // współczynnik przy x^2
}


//aproksymacja cos^2(x)*sin(x) od 0 do pi/2