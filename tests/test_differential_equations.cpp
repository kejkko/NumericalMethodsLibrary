#include <gtest/gtest.h>
#include "../include/differential_equations.h"
#include <cmath>

TEST(DifferentialEquationsTest, EulerMethod_YEqualsY) {
    auto f = [](double x, double y) { return y; };
    std::vector<double> y = euler_method(f, 0, 1, 0.1, 10);
    EXPECT_NEAR(y[10], std::exp(1.0), 0.13);
}

TEST(DifferentialEquationsTest, EulerMethod_YEqualsX) {
    auto f = [](double x, double y) { return x; };
    std::vector<double> y = euler_method(f, 0, 0, 0.1, 10);
    EXPECT_NEAR(y[10], 0.5, 0.1);
}

TEST(DifferentialEquationsTest, HeunMethod_YEqualsY) {
    auto f = [](double x, double y) { return y; };
    std::vector<double> y = heun_method(f, 0, 1, 0.1, 10);
    EXPECT_NEAR(y[10], std::exp(1.0), 0.01);
}

TEST(DifferentialEquationsTest, HeunMethod_YEqualsX) {
    auto f = [](double x, double y) { return x; };
    std::vector<double> y = heun_method(f, 0, 0, 0.1, 10);
    EXPECT_NEAR(y[10], 0.5, 0.01);
}

TEST(DifferentialEquationsTest, MidpointMethod_YEqualsY) {
    auto f = [](double x, double y) { return y; };
    std::vector<double> y = midpoint_method(f, 0, 1, 0.1, 10);
    EXPECT_NEAR(y[10], std::exp(1.0), 0.01);
}

TEST(DifferentialEquationsTest, MidpointMethod_YEqualsX) {
    auto f = [](double x, double y) { return x; };
    std::vector<double> y = midpoint_method(f, 0, 0, 0.1, 10);
    EXPECT_NEAR(y[10], 0.5, 0.01);
}

TEST(DifferentialEquationsTest, RungeKutta4_YEqualsY) {
    auto f = [](double x, double y) { return y; };
    std::vector<double> y = runge_kutta_4(f, 0, 1, 0.1, 10);
    EXPECT_NEAR(y[10], std::exp(1.0), 1e-5);
}

TEST(DifferentialEquationsTest, RungeKutta4_YEqualsX) {
    auto f = [](double x, double y) { return x; };
    std::vector<double> y = runge_kutta_4(f, 0, 0, 0.1, 10);
    EXPECT_NEAR(y[10], 0.5, 1e-5);
}
