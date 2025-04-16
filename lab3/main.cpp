#include <iostream>
#include <iomanip>
#include "Func.h"

using namespace std;

int main() {
    int method;
    cout << "Choose method:\n1. Bisection\n2. Newton\n> ";
    cin >> method;

    try {
        if (method == 1) {
            double a, b;
            cout << "Enter interval [a, b]: ";
            cin >> a >> b;

            BisectionSolver solver(a, b);
            double root = solver.solve();
            cout << "Root found by Bisection: " << root << "\n";
        } else if (method == 2) {
            double x0;
            cout << "Enter initial guess: ";
            cin >> x0;

            NewtonSolver solver(x0);
            double root = solver.solve();
            cout << "Root found by Newton's Method: " << root << "\n";
        } else {
            cout << "Invalid method selected.\n";
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}