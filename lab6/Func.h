#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

class BisectionSolver {
public:
    BisectionSolver(function<double(double)> f, double a, double b, double epsilon = 1e-6);

    double solve();

private:
    function<double(double)> f;
    double a, b, epsilon;
};

class NewtonSolver {
public:
    NewtonSolver(function<double(double)> f,
                 function<double(double)> fPrime,
                 double x0, double epsilon = 1e-6, int maxIter = 100);

    double solve();

private:
    function<double(double)> f;
    function<double(double)> fPrime;
    double x0, epsilon;
    int maxIter;
};

#endif //FUNC_H
