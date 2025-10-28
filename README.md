# Biblioteka Metod Numerycznych

## Opis
Biblioteka implementująca podstawowe metody numeryczne w języku C++.

## Struktura
```
biblioteczka/
├── include/           # pliki nagłówkowe
├── src/               # implementacje
├── tests/             # testy jednostkowe
├── examples/          # przykłady użycia
├── CMakeLists.txt     # cmake
├── Makefile           # make
└── README.md          # dokumentacja
```

## Funkcjonalności

### Układy równań liniowych
- `gauss_elimination(A, b)` - eliminacja Gaussa
  - A: macierz współczynników
  - b: wektor wyrazów wolnych
  - zwraca: wektor rozwiązań

- `lu_decomposition(A, b)` - rozkład LU
  - A: macierz współczynników
  - b: wektor wyrazów wolnych
  - zwraca: wektor rozwiązań

### Interpolacja
- `lagrange_interpolation(x, y, xi)` - interpolacja Lagrange'a
  - x, y: wektory punktów
  - xi: punkt interpolacji
  - zwraca: wartość interpolowaną

- `newton_interpolation(x, y, xi)` - interpolacja Newtona
  - x, y: wektory punktów
  - xi: punkt interpolacji
  - zwraca: wartość interpolowaną

### Aproksymacja
- `least_squares_approximation(x, y, degree)` - aproksymacja średniokwadratowa
  - x, y: wektory punktów
  - degree: stopień wielomianu
  - zwraca: wektor współczynników

### Całkowanie numeryczne
- `rectangle_method(f, a, b, n)` - metoda prostokątów
- `trapezoidal_method(f, a, b, n)` - metoda trapezów
- `simpson_method(f, a, b, n)` - metoda Simpsona
- `gauss_legendre_2/3/4(f, a, b)` - kwadratury Gaussa-Legendre'a
  - f: funkcja do całkowania
  - a, b: granice całkowania
  - n: liczba przedziałów
  - zwraca: wartość całki

### Równania różniczkowe
- `euler_method(f, x0, y0, h, n)` - metoda Eulera
- `heun_method(f, x0, y0, h, n)` - metoda Heuna
- `midpoint_method(f, x0, y0, h, n)` - metoda punktu środkowego
- `runge_kutta_4(f, x0, y0, h, n)` - Runge-Kutta 4. rzędu
  - f: funkcja prawej strony y' = f(x,y)
  - x0, y0: warunki początkowe
  - h: krok całkowania
  - n: liczba kroków
  - zwraca: wektor wartości rozwiązania

### Równania nieliniowe
- `newton_method(f, df, x0, tol, max_iter)` - metoda Newtona
  - f: funkcja
  - df: pochodna funkcji
  - x0: punkt startowy
  - tol: tolerancja
  - max_iter: maksymalna liczba iteracji
  - zwraca: pierwiastek

- `secant_method(f, x0, x1, tol, max_iter)` - metoda siecznych
  - f: funkcja
  - x0, x1: punkty startowe
  - tol: tolerancja
  - max_iter: maksymalna liczba iteracji
  - zwraca: pierwiastek

- `bisection_method(f, a, b, tol, max_iter)` - metoda bisekcji
  - f: funkcja
  - a, b: przedział
  - tol: tolerancja
  - max_iter: maksymalna liczba iteracji
  - zwraca: pierwiastek

## Kompilacja

### CMake
```bash
mkdir build && cd build
cmake ..
make
```

### Make
```bash
make all
make tests
make examples
make run-tests
```

## Użycie
```cpp
#include "linear_systems.h"
#include "interpolation.h"

vector<vector<double>> A = {{2, 1}, {1, 3}};
vector<double> b = {3, 4};
vector<double> x = gauss_elimination(A, b);

vector<double> px = {0, 1, 2};
vector<double> py = {1, 2, 5};
double val = lagrange_interpolation(px, py, 1.5);
```
