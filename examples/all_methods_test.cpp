#include "../include/linear_systems.h"
#include "../include/interpolation.h"
#include "../include/approximation.h"
#include "../include/integration.h"
#include "../include/differential_equations.h"
#include "../include/nonlinear_equations.h"
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

void test_linear_systems() {
    cout << "=== UKLADY ROWNAN LINIOWYCH ===" << endl;

    cout << "Podaj rozmiar macierzy: ";
    int n;
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Podaj elementy macierzy A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Podaj wektor b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Wybierz metode (1-Gauss, 2-LU): ";
    int method;
    cin >> method;

    vector<double> x;
    if (method == 1) {
        x = gauss_elimination(A, b);
    } else {
        x = lu_decomposition(A, b);
    }

    cout << "Rozwiazanie:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

void test_interpolation() {
    cout << "=== INTERPOLACJA ===" << endl;

    cout << "Podaj liczbe punktow: ";
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Podaj punkty (x y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout << "Podaj punkt do interpolacji: ";
    double xi;
    cin >> xi;

    cout << "Wybierz metode (1-Lagrange, 2-Newton): ";
    int method;
    cin >> method;

    double result;
    if (method == 1) {
        result = lagrange_interpolation(x, y, xi);
    } else {
        result = newton_interpolation(x, y, xi);
    }

    cout << "Wartosc interpolowana: " << result << endl;
}

void test_approximation() {
    cout << "=== APROKSYMACJA ===" << endl;

    cout << "Dostepne funkcje do aproksymacji:" << endl;
    cout << "1. x^2" << endl;
    cout << "2. sin(x)" << endl;
    cout << "3. e^x" << endl;
    cout << "4. ln(x) (x>0)" << endl;
    cout << "5. cos^2(x)*sin(x)" << endl;

    cout << "Wybierz funkcje: ";
    int func_choice;
    cin >> func_choice;

    function<double(double)> f;
    switch (func_choice) {
        case 1: f = [](double x) { return x * x; }; break;
        case 2: f = [](double x) { return sin(x); }; break;
        case 3: f = [](double x) { return exp(x); }; break;
        case 4: f = [](double x) { return log(x); }; break;
        case 5: f = [](double x) { return cos(x) * cos(x) * sin(x); }; break;
        default:
            cout << "Nieznana funkcja, domyslnie x^2" << endl;
        f = [](double x) { return x * x; };
    }

    cout << "Podaj przedzial aproksymacji (a b): ";
    double a, b;
    cin >> a >> b;

    cout << "Podaj liczbe punktow do wygenerowania: ";
    int n;
    cin >> n;

    cout << "Podaj stopien wielomianu do aproksymacji: ";
    int degree;
    cin >> degree;

    // Generujemy punkty (x,y)
    vector<double> x(n), y(n);
    double step = (b - a) / (n - 1);
    for (int i = 0; i < n; i++) {
        x[i] = a + i * step;
        y[i] = f(x[i]);
    }

    vector<double> coeffs = least_squares_approximation(x, y, degree);

    cout << "Wspolczynniki wielomianu aproksymujacego:" << endl;
    for (int i = 0; i < (int)coeffs.size(); i++) {
        cout << "a" << i << " = " << coeffs[i] << endl;
    }

    cout << "Wielomian: ";
    for (int i = (int)coeffs.size() - 1; i >= 0; i--) {
        if (coeffs[i] != 0) {
            if (i != (int)coeffs.size() - 1 && coeffs[i] > 0) {
                cout << " + ";
            } else if (i != (int)coeffs.size() - 1 && coeffs[i] < 0) {
                cout << " ";
            }

            if (i == 0) {
                cout << coeffs[i];
            } else if (i == 1) {
                cout << coeffs[i] << "x";
            } else {
                cout << coeffs[i] << "x^" << i;
            }
        }
    }
    cout << endl;
}


void test_integration() {
    cout << "=== CALKOWANIE NUMERYCZNE ===" << endl;
    cout << "Dostepne funkcje:" << endl;
    cout << "1. x^2" << endl;
    cout << "2. sin(x)" << endl;
    cout << "3. e^x" << endl;
    cout << "4. 1/x" << endl;

    cout << "Wybierz funkcje: ";
    int func_choice;
    cin >> func_choice;

    function<double(double)> f;
    switch (func_choice) {
        case 1: f = [](double x) { return x * x; }; break;
        case 2: f = [](double x) { return sin(x); }; break;
        case 3: f = [](double x) { return exp(x); }; break;
        case 4: f = [](double x) { return 1.0 / x; }; break;
        default: f = [](double x) { return x * x; };
    }

    cout << "Podaj przedzial calkowania (a b): ";
    double a, b;
    cin >> a >> b;

    cout << "Wybierz metode:" << endl;
    cout << "1. Prostokaty" << endl;
    cout << "2. Trapezy" << endl;
    cout << "3. Simpson" << endl;
    cout << "4. Gauss-Legendre 2 wezly" << endl;
    cout << "5. Gauss-Legendre 3 wezly" << endl;
    cout << "6. Gauss-Legendre 4 wezly" << endl;

    int method;
    cin >> method;

    double result;
    if (method <= 3) {
        cout << "Podaj liczbe przedzialow: ";
        int n;
        cin >> n;

        switch (method) {
            case 1: result = rectangle_method(f, a, b, n); break;
            case 2: result = trapezoidal_method(f, a, b, n); break;
            case 3: result = simpson_method(f, a, b, n); break;
        }
    } else {
        switch (method) {
            case 4: result = gauss_legendre_2(f, a, b); break;
            case 5: result = gauss_legendre_3(f, a, b); break;
            case 6: result = gauss_legendre_4(f, a, b); break;
        }
    }

    cout << "Wartosc calki: " << result << endl;
}

void test_differential_equations() {
    cout << "=== ROWNANIA ROZNICZKOWE ===" << endl;
    cout << "Dostepne rownania:" << endl;
    cout << "1. y' = y (rozwiazanie: y = C*e^x)" << endl;
    cout << "2. y' = x (rozwiazanie: y = x^2/2 + C)" << endl;
    cout << "3. y' = -2y + x" << endl;
    cout << "4. y' = y - x^2" << endl;

    cout << "Wybierz rownanie: ";
    int eq_choice;
    cin >> eq_choice;

    function<double(double, double)> f;
    switch (eq_choice) {
        case 1: f = [](double x, double y) { return y; }; break;
        case 2: f = [](double x, double y) { return x; }; break;
        case 3: f = [](double x, double y) { return -2 * y + x; }; break;
        case 4: f = [](double x, double y) { return y - x * x; }; break;
        default: f = [](double x, double y) { return y; };
    }

    cout << "Podaj warunki poczatkowe (x0 y0): ";
    double x0, y0;
    cin >> x0 >> y0;

    cout << "Podaj krok h: ";
    double h;
    cin >> h;

    cout << "Podaj liczbe krokow n: ";
    int n;
    cin >> n;

    cout << "Wybierz metode:" << endl;
    cout << "1. Euler" << endl;
    cout << "2. Heun" << endl;
    cout << "3. Punkt srodkowy" << endl;
    cout << "4. Runge-Kutta 4" << endl;

    int method;
    cin >> method;

    vector<double> solution;
    switch (method) {
        case 1: solution = euler_method(f, x0, y0, h, n); break;
        case 2: solution = heun_method(f, x0, y0, h, n); break;
        case 3: solution = midpoint_method(f, x0, y0, h, n); break;
        case 4: solution = runge_kutta_4(f, x0, y0, h, n); break;
    }

    cout << "Rozwiazanie:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "y(" << x0 + i * h << ") = " << solution[i] << endl;
    }
}

void test_nonlinear_equations() {
    cout << "=== ROWNANIA NIELINIOWE ===" << endl;
    cout << "Dostepne funkcje:" << endl;
    cout << "1. x^2 - 4" << endl;
    cout << "2. x^3 - 8" << endl;
    cout << "3. cos(x) - x" << endl;
    cout << "4. e^x - 2" << endl;

    cout << "Wybierz funkcje: ";
    int func_choice;
    cin >> func_choice;

    function<double(double)> f, df;
    switch (func_choice) {
        case 1:
            f = [](double x) { return x * x - 4; };
            df = [](double x) { return 2 * x; };
            break;
        case 2:
            f = [](double x) { return x * x * x - 8; };
            df = [](double x) { return 3 * x * x; };
            break;
        case 3:
            f = [](double x) { return cos(x) - x; };
            df = [](double x) { return -sin(x) - 1; };
            break;
        case 4:
            f = [](double x) { return exp(x) - 2; };
            df = [](double x) { return exp(x); };
            break;
        default:
            f = [](double x) { return x * x - 4; };
            df = [](double x) { return 2 * x; };
    }

    cout << "Wybierz metode:" << endl;
    cout << "1. Newton" << endl;
    cout << "2. Siecznych" << endl;
    cout << "3. Bisekcja" << endl;

    int method;
    cin >> method;

    cout << "Podaj tolerancje: ";
    double tol;
    cin >> tol;

    cout << "Podaj maksymalna liczbe iteracji: ";
    int max_iter;
    cin >> max_iter;

    double result;
    if (method == 1) {
        cout << "Podaj punkt startowy: ";
        double x0;
        cin >> x0;
        result = newton_method(f, df, x0, tol, max_iter);
    } else if (method == 2) {
        cout << "Podaj dwa punkty startowe: ";
        double x0, x1;
        cin >> x0 >> x1;
        result = secant_method(f, x0, x1, tol, max_iter);
    } else {
        cout << "Podaj przedzial (a b): ";
        double a, b;
        cin >> a >> b;
        result = bisection_method(f, a, b, tol, max_iter);
    }

    cout << "Pierwiastek: " << result << endl;
}

int main() {
    cout << "BIBLIOTECZKA - METODY NUMERYCZNE" << endl;
    cout << "=================================" << endl;

    while (true) {
        cout << "\nWybierz kategorie:" << endl;
        cout << "1. Uklady rownan liniowych" << endl;
        cout << "2. Interpolacja" << endl;
        cout << "3. Aproksymacja" << endl;
        cout << "4. Calkowanie numeryczne" << endl;
        cout << "5. Rownania rozniczkowe" << endl;
        cout << "6. Rownania nieliniowe" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: test_linear_systems(); break;
            case 2: test_interpolation(); break;
            case 3: test_approximation(); break;
            case 4: test_integration(); break;
            case 5: test_differential_equations(); break;
            case 6: test_nonlinear_equations(); break;
            case 0: return 0;
            default: cout << "Nieprawidlowy wybor!" << endl;
        }
    }
}