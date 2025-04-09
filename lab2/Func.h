#ifndef FUNC_H
#define FUNC_H

struct Point {
    double x, y;
};

struct Triangle {
    Point a, b, c;
    bool containsVector(const Point &p) const;
    bool isDegenerate() const;
};

double distance(const Point &p1, const Point &p2);
double vector(const Point &a, const Point &b, const Point &p);
bool linePoint(const Point &p, const Point &a, const Point &b);
double roundToInt(double value);

#endif //FUNC_H
