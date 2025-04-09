#include "Func.h"
#include <valarray>

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double vector(const Point &a, const Point &b, const Point &p) {
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

bool Triangle::containsVector(const Point &p) const {
    if (isDegenerate()) return false;

    double w1 = vector(a, b, p);
    double w2 = vector(b, c, p);
    double w3 = vector(c, a, p);

    return (w1 >= 0 && w2 >= 0 && w3 >= 0) || (w1 <= 0 && w2 <= 0 && w3 <= 0);
}

bool Triangle::isDegenerate() const {
    return fabs(vector(a, b, c)) < 1e-9;
}

bool linePoint(const Point &p, const Point &a, const Point &b) {
    if (fabs(vector(a, b, p)) > 1e-9) return false;

    double dot = (p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y);
    if (dot < 0) return false;

    double distance = pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
    if (dot > distance) return false;

    return true;
}

double roundToInt(double value) {
    double epsilon = 1e-2 + 1e-9;

    if (fabs(value - round(value)) <= epsilon) {
        return round(value);
    }
    return value;
}
