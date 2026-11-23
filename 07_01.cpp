#include <iostream>

struct Vec2 {
    int x;
    int y;

    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }
};

Vec2 operator+(Vec2 a, const Vec2& b) {
    a += b;
    return a;
}

Vec2 operator-(Vec2 a, const Vec2& b) {
    a -= b;
    return a;
}

Vec2 operator*(Vec2 v, int n) {
    v.x *= n;
    v.y *= n;
    return v;
}

Vec2 operator*(int n, Vec2 v) {
    return v * n;
}

std::ostream& operator<<(std::ostream& out, const Vec2& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}