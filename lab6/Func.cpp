#include "Func.h"

BisectionSolver::BisectionSolver(function<double(double)> f, double a, double b, double epsilon)
    : f(f), a(a), b(b), epsilon(epsilon) {
}

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

NewtonSolver::NewtonSolver(function<double(double)> f,
                           function<double(double)> fPrime,
                           double x0, double epsilon, int maxIter)
    : f(f), fPrime(fPrime), x0(x0), epsilon(epsilon), maxIter(maxIter) {
}

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
