#include <gtest/gtest.h>
#include <cmath>
#include "../include/nonlinear_equations.h"

TEST(NonlinearEquationsTest, NewtonMethod_Sqrt2) {
    auto f = [](double x) { return x * x - 2; };
    auto df = [](double x) { return 2 * x; };
    double root = newton_method(f, df, 1, 1e-10, 100);
    EXPECT_NEAR(root, std::sqrt(2), 1e-10);
}

TEST(NonlinearEquationsTest, NewtonMethod_CubeRoot2) {
    auto f = [](double x) { return x * x * x - 8; };
    auto df = [](double x) { return 3 * x * x; };
    double root = newton_method(f, df, 1, 1e-10, 100);
    EXPECT_NEAR(root, 2.0, 1e-10);
}

TEST(NonlinearEquationsTest, SecantMethod_Sqrt2) {
    auto f = [](double x) { return x * x - 2; };
    double root = secant_method(f, 1, 2, 1e-10, 100);
    EXPECT_NEAR(root, std::sqrt(2), 1e-10);
}

TEST(NonlinearEquationsTest, SecantMethod_CubeRoot2) {
    auto f = [](double x) { return x * x * x - 8; };
    double root = secant_method(f, 1, 3, 1e-10, 100);
    EXPECT_NEAR(root, 2.0, 1e-10);
}

TEST(NonlinearEquationsTest, BisectionMethod_Sqrt2) {
    auto f = [](double x) { return x * x - 2; };
    double root = bisection_method(f, 1, 2, 1e-10, 100);
    EXPECT_NEAR(root, std::sqrt(2), 1e-10);
}

TEST(NonlinearEquationsTest, BisectionMethod_CubeRoot2) {
    auto f = [](double x) { return x * x * x - 8; };
    double root = bisection_method(f, 1, 3, 1e-10, 100);
    EXPECT_NEAR(root, 2.0, 1e-10);
}
