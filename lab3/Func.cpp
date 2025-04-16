#include "Func.h"
#include <cmath>
#include <iostream>

using namespace std;

double BisectionSolver::f(double x) {
    double denominator = 3 - sin(3.6 * x);
    if (denominator == 0) {
        throw runtime_error("Denominator is zero, division by zero error.");
    }
    return x - 1.0 / denominator;
}

BisectionSolver::BisectionSolver(double a, double b, double epsilon)
    : a(a), b(b), epsilon(epsilon) {}

double BisectionSolver::solve() {
    double left = a;
    double right = b;
    double mid;

    if (f(left) * f(right) > 0) {
        throw invalid_argument("Function has same sign at the endpoints.");
    }

    while ((right - left) > epsilon) {
        mid = (left + right) / 2.0;
        if (f(left) * f(mid) < 0)
            right = mid;
        else
            left = mid;
    }

    return (left + right) / 2.0;
}

double NewtonSolver::f(double x) {
    return x - 1.0 / (3 - sin(3.6 * x));
}

double NewtonSolver::fPrime(double x) {
    double denominator = 3 - sin(3.6 * x);
    if (fabs(denominator) < 1e-12) {
        throw runtime_error("Derivative too small, division by zero error.");
    }
    double dSin = 3.6 * cos(3.6 * x);
    return 1.0 + dSin / (denominator * denominator);
}

NewtonSolver::NewtonSolver(double x0, double epsilon, int maxIter)
    : x0(x0), epsilon(epsilon), maxIter(maxIter) {}

double NewtonSolver::solve() {
    double x = x0;

    for (int i = 0; i < maxIter; ++i) {
        double fx = f(x);
        double fpx = fPrime(x);

        if (abs(fpx) < 1e-12) {
            throw runtime_error("Derivative too small.");
        }

        double next = x - fx / fpx;

        if (abs(next - x) < epsilon) {
            return next;
        }

        x = next;
    }

    throw runtime_error("Newton method did not converge.");
}