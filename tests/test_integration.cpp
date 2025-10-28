#include <gtest/gtest.h>
#include <cmath>
#include "../include/integration.h"

TEST(IntegrationTest, RectangleMethod_XSquared) {
    auto f = [](double x) { return x * x; };
    double result = rectangle_method(f, 0, 1, 1000);
    EXPECT_NEAR(result, 1.0 / 3, 1e-3);
}

TEST(IntegrationTest, RectangleMethod_2X) {
    auto f = [](double x) { return 2 * x; };
    double result = rectangle_method(f, 0, 2, 1000);
    EXPECT_NEAR(result, 4.0, 1e-2);
}

TEST(IntegrationTest, TrapezoidalMethod_XSquared) {
    auto f = [](double x) { return x * x; };
    double result = trapezoidal_method(f, 0, 1, 1000);
    EXPECT_NEAR(result, 1.0 / 3, 1e-6);
}

TEST(IntegrationTest, TrapezoidalMethod_2X) {
    auto f = [](double x) { return 2 * x; };
    double result = trapezoidal_method(f, 0, 2, 1000);
    EXPECT_NEAR(result, 4.0, 1e-6);
}

TEST(IntegrationTest, SimpsonMethod_XSquared) {
    auto f = [](double x) { return x * x; };
    double result = simpson_method(f, 0, 1, 1000);
    EXPECT_NEAR(result, 1.0 / 3, 1e-10);
}

TEST(IntegrationTest, SimpsonMethod_XCubed) {
    auto f = [](double x) { return x * x * x; };
    double result = simpson_method(f, 0, 2, 1000);
    EXPECT_NEAR(result, 4.0, 1e-10);
}

TEST(IntegrationTest, GaussLegendre2_XSquared) {
    auto f = [](double x) { return x * x; };
    double result = gauss_legendre_2(f, 0, 1);
    EXPECT_NEAR(result, 1.0 / 3, 1e-10);
}

TEST(IntegrationTest, GaussLegendre2_X) {
    auto f = [](double x) { return x; };
    double result = gauss_legendre_2(f, 0, 2);
    EXPECT_NEAR(result, 2.0, 1e-10);
}

TEST(IntegrationTest, GaussLegendre3_XCubed) {
    auto f = [](double x) { return x * x * x; };
    double result = gauss_legendre_3(f, 0, 1);
    EXPECT_NEAR(result, 0.25, 1e-10);
}

TEST(IntegrationTest, GaussLegendre3_XSquared) {
    auto f = [](double x) { return x * x; };
    double result = gauss_legendre_3(f, 0, 2);
    EXPECT_NEAR(result, 8.0 / 3, 1e-10);
}

TEST(IntegrationTest, GaussLegendre4_XPow4) {
    auto f = [](double x) { return x * x * x * x; };
    double result = gauss_legendre_4(f, 0, 1);
    EXPECT_NEAR(result, 0.2, 1e-10);
}

TEST(IntegrationTest, GaussLegendre4_XCubed) {
    auto f = [](double x) { return x * x * x; };
    double result = gauss_legendre_4(f, 0, 2);
    EXPECT_NEAR(result, 4.0, 1e-10);
}
