long double add(long double a, long double b) {
    return (abs(a + b) < EPS * (abs(a) + abs(b))) ? 0 : a + b;
}

struct Point {
    long double x, y;
    Point (long double x, long double y) : x(x), y(y) {}
    Point () = default;

    Point operator + (const Point & point) const {
        return Point(add(x,point.x), add(y,point.y));
    }
    Point operator - (const Point & point) const {
        return Point(add(x,-point.x), add(y,-point.y));
    }
    Point operator * (const long double d) const {
        return Point(x * d, y * d);
    }
    Point operator / (const long double d) const {
        return Point(x / d, y / d);
    }
    Point operator * (const Point & point) const {
        return Point(add(x * point.x, -y * point.y), add(x * point.y, y * point.x));
    }
};

struct Circle {
    Point center;
    long double radius;
    Circle (Point center, long double radius) : center(center), radius(radius) {}
    Circle () = default;
};

long double getSquareDistance(Point const & a, Point const & b) {
    return pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2);
}

long double getDistance(Point const & a, Point const & b) {
    return sqrt(getSquareDistance(a, b));
}

vector<Point> getIntersections(Circle const & a, Circle const & b) {
    // Intersections should exist.
    assert(getDistance(a.center, b.center) < a.radius + b.radius);

    vector<Point> intersections;
//    // No intersections.
//    if (abs(a.radius - b.radius) - getDistance(a.center, b.center) > EPS) { // included
//        return intersections;
//    }
    long double d = getDistance(a.center, b.center);
    Point diff = (b.center - a.center) / d;
    long double rc = (d * d + pow(a.radius, 2) - pow(b.radius, 2)) / (2 * d);
    if (abs(getDistance(a.center, b.center) - (a.radius + b.radius)) < EPS) {
        intersections = {a.center + diff * Point(rc, 0)};
    } else {
        long double rs = sqrt(pow(a.radius, 2) - pow(rc, 2));
//        assert(!isnan(rs));
        intersections = {a.center + diff * Point(rc, rs), a.center + diff * Point(rc, -rs)};
    }
//    for (const auto & intersection : intersections) {
//        assert(abs(getDistance(a.center, intersection) - a.radius) < EPS);
//        assert(abs(getDistance(b.center, intersection) - b.radius) < EPS);
//    }
    return intersections;
}
