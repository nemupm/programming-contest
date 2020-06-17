typedef long double FLOAT_TYPE;

int sgn(const FLOAT_TYPE & r) {
    return (r > EPS) - (r < - EPS);
}

int sgn(const FLOAT_TYPE & a, const FLOAT_TYPE & b) {
    return sgn(a - b);
}

FLOAT_TYPE add(FLOAT_TYPE a, FLOAT_TYPE b) {
    return (abs(a + b) < EPS * (abs(a) + abs(b))) ? 0 : a + b;
}

struct Point {
    FLOAT_TYPE x, y;
    Point (FLOAT_TYPE x, FLOAT_TYPE y) : x(x), y(y) {}
    Point () = default;

    Point operator + (const Point & point) const {
        return Point(add(x,point.x), add(y,point.y));
    }
    Point operator - (const Point & point) const {
        return Point(add(x,-point.x), add(y,-point.y));
    }
    Point operator * (const FLOAT_TYPE d) const {
        return Point(x * d, y * d);
    }
    Point operator / (const FLOAT_TYPE d) const {
        return Point(x / d, y / d);
    }
    Point operator * (const Point & point) const {
        return Point(add(x * point.x, -y * point.y), add(x * point.y, y * point.x));
    }
};

template<class NUMBER>
struct Point {
    NUMBER x, y;
    Point (NUMBER x, NUMBER y) : x(x), y(y) {}
    Point () = default;

    Point operator + (const Point & point) const {
        return Point(x + point.x, y + point.y);
    }
    Point operator - (const Point & point) const {
        return Point(x - point.x, y, - point.y);
    }
    Point operator * (const NUMBER d) const {
        return Point(x * d, y * d);
    }
    Point operator / (const NUMBER d) const {
        return Point(x / d, y / d);
    }
    Point& operator += (const Point & point) {
        x += point.x;
        y += point.y;
        return *this;
    }
    Point& operator -= (const Point & point) {
        x -= point.x;
        y -= point.y;
        return *this;
    }
    Point& operator *= (const NUMBER d) {
        x *= d;
        y *= d;
        return *this;
    }
    Point& operator /= (const NUMBER d) {
        x /= d;
        y /= d;
        return *this;
    }
    bool operator < (const Point& point) const {
        return x < point.x && y < point.y;
    }
};

struct Circle {
    Point center;
    FLOAT_TYPE radius;
    Circle (Point center, FLOAT_TYPE radius) : center(center), radius(radius) {}
    Circle () = default;
};

FLOAT_TYPE getSquareDistance(Point const & a, Point const & b) {
    return pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2);
}

FLOAT_TYPE getDistance(Point const & a, Point const & b) {
    return sqrt(getSquareDistance(a, b));
}

vector<Point> getIntersections(Circle const & a, Circle const & b) {
    // Intersections should exist.
    dassert(sgn(getDistance(a.center, b.center), a.radius + b.radius) < 0); // should not be too far
    dassert(sgn(getDistance(a.center, b.center), abs(a.radius - b.radius)) > 0); // should not be included

    vector<Point> intersections;
    FLOAT_TYPE d = getDistance(a.center, b.center);
    Point diff = (b.center - a.center) / d;
    FLOAT_TYPE rc = (d * d + pow(a.radius, 2) - pow(b.radius, 2)) / (2 * d);
    if (abs(getDistance(a.center, b.center) - (a.radius + b.radius)) < EPS) {
        intersections = {a.center + diff * Point(rc, 0)};
    } else {
        FLOAT_TYPE rs = sqrt(pow(a.radius, 2) - pow(rc, 2));
        dassert(!isnan(rs));
        if (isnan(rs)) return intersections;
        intersections = {a.center + diff * Point(rc, rs), a.center + diff * Point(rc, -rs)};
    }
    for (const auto & intersection : intersections) {
        dassert(abs(getDistance(a.center, intersection) - a.radius) < EPS);
        dassert(abs(getDistance(b.center, intersection) - b.radius) < EPS);
    }
    return intersections;
}
