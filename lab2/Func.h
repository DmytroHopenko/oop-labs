#ifndef FUNC_H
#define FUNC_H

struct Point {
    double x, y;
};

struct Triangle {
    Point a, b, c;
    double area() const;
    bool contains(const Point &p) const;
    bool containsVector(const Point &p) const;
    bool isDegenerate() const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
double vector(const Point &a, const Point &b, const Point &p);
bool linePoint(const Point &p, const Point &a, const Point &b);

#endif //FUNC_H
