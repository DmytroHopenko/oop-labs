#include <iostream>
#include "Func.h"

using namespace std;

int main() {
    Triangle t;

    cout << "Enter the coordinates of the triangle ex(x1 y1 x2 y2 x3 y3): ";
    cin >> t.a.x >> t.a.y >> t.b.x >> t.b.y >> t.c.x >> t.c.y;

    t.a.x = roundToInt(t.a.x);
    t.a.y = roundToInt(t.a.y);
    t.b.x = roundToInt(t.b.x);
    t.b.y = roundToInt(t.b.y);
    t.c.x = roundToInt(t.c.x);
    t.c.y = roundToInt(t.c.y);

    cout << "Top A(" << t.a.x << ", " << t.a.y << "), B(" << t.b.x << ", " << t.b.y << "), C(" << t.c.x << ", " << t.c.y
            << ")" << endl;

    if (t.isDegenerate()) cout << "Triangle is degenerate" << endl;

    int k, method;

    while (true) {
        cout << "Pick method" << endl;
        cout << "1. Areas method" << endl;
        cout << "2. Vector method" << endl;

        cin >> method;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Choose 1 or 2." << endl;
            cout << "Invalid input! Enter a positive number" << endl;
            continue;
        }

        if (method == 1 || method == 2) break;
    }

    switch (method) {
        case 1:
            int n;
            while (true) {
                cout << "Enter the number of points to check: ";
                cin >> n;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter a positive number" << endl;
                    continue;
                }
                if (n > 0) {
                    break;
                }
                cout << "Incorrect choice! Enter a positive number" << endl;
            }

            for (int i = 0; i < n; ++i) {
                Point p;
                cout << "Enter the coordinates of the point (x y): ";
                cin >> p.x >> p.y;

                p.x = roundToInt(p.x);
                p.y = roundToInt(p.y);

                if ((p.x == t.a.x && p.y == t.a.y) || (p.x == t.b.x && p.y == t.b.y) || (
                        p.x == t.c.x && p.y == t.c.y)) {
                    cout << "The point is equal to the vertex of the triangle." << endl;
                } else if (linePoint(p, t.a, t.b) || linePoint(p, t.b, t.c) || linePoint(p, t.c, t.a)) {
                    cout << "The point lies on the boundary of the triangle." << endl;
                } else if (t.containsVector(p)) {
                    cout << "The point belongs to the triangle" << endl;
                } else {
                    cout << "The point does not belong to the triangle." << endl;
                }
            }
            break;
        case 2:
            int k;
            while (true) {
                cout << "Enter the number of points to check: ";
                cin >> k;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter a positive number" << endl;
                    continue;
                }
                if (k > 0) {
                    break;
                }
                cout << "Incorrect choice! Enter a positive number" << endl;
            }

            for (int i = 0; i < k; ++i) {
                Point p;
                cout << "Enter the coordinates of the point (x y): ";
                cin >> p.x >> p.y;

                p.x = roundToInt(p.x);
                p.y = roundToInt(p.y);

                if ((p.x == t.a.x && p.y == t.a.y) || (p.x == t.b.x && p.y == t.b.y) || (
                        p.x == t.c.x && p.y == t.c.y)) {
                    cout << "The point is equal to the vertex of the triangle." << endl;
                } else if (linePoint(p, t.a, t.b) || linePoint(p, t.b, t.c) || linePoint(p, t.c, t.a)) {
                    cout << "The point lies on the boundary of the triangle." << endl;
                } else if (t.containsVector(p)) {
                    cout << "The point belongs to the triangle" << endl;
                } else {
                    cout << "The point doesn't belong to the triangle" << endl;
                }
            }
            break;

        default:
            break;
    }

    return 0;
}
