#include "Func.h"

int main() {
    auto f = [](double x) -> double {
        return x - 1.0 / (3 - sin(3.6 * x));
    };

    auto fPrime = [](double x) -> double {
        double denominator = 3 - sin(3.6 * x);
        if (fabs(denominator) < 1e-12) {
            throw runtime_error("Derivative too small");
        }
        double dSin = 3.6 * cos(3.6 * x);
        return 1.0 + dSin / (denominator * denominator);
    };

    const double epsilon = 1e-6;
    const int maxIter = 100;

    int methodChoice;
    cout << "Choose method to solve the equation:\n";
    cout << "1. Bisection Method\n";
    cout << "2. Newton's Method\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> methodChoice;

    try {
        if (methodChoice == 1) {
            double a, b;
            cout << "Enter interval [a, b]: ";
            cin >> a >> b;

            BisectionSolver bisect(f, a, b, epsilon);
            double root = bisect.solve();
            cout << "Root (Bisection): " << root << endl;
        } else if (methodChoice == 2) {
            double x0;
            cout << "Enter starting point x0: ";
            cin >> x0;

            NewtonSolver newton(f, fPrime, x0, epsilon, maxIter);
            double root = newton.solve();
            cout << "Root (Newton): " << root << endl;
        } else {
            cout << "Invalid method selected!" << endl;
        }
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
