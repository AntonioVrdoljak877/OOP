#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
};

Vec2 operator-(Vec2 a, const Vec2& b) {
    a -= b;
    return a;
}

struct Enemy {
    std::string ime;
    Vec2 polozaj;
};

struct InRange {
    Vec2 centar;
    int domet;

    InRange(Vec2 c, int d) : centar(c), domet(d) {}

    bool operator()(const Enemy& e) const {
        int dx = e.polozaj.x - centar.x;
        int dy = e.polozaj.y - centar.y;
        return dx * dx + dy * dy <= domet * domet;
    }
};

int main() {
    std::vector<Enemy> neprijatelji = {
        {"Goblin", {1, 1}},
        {"Orc", {3, 4}},
        {"Troll", {5, 0}},
        {"Skeleton", {0, 2}},
        {"Dragon", {10, 10}}
    };

    Vec2 igrac{0, 0};
    int domet = 5;

    int n1 = std::count_if(neprijatelji.begin(), neprijatelji.end(),
                           InRange(igrac, domet));

    int n2 = std::count_if(neprijatelji.begin(), neprijatelji.end(),
                           [igrac, domet](const Enemy& e) {
                               int dx = e.polozaj.x - igrac.x;
                               int dy = e.polozaj.y - igrac.y;
                               return dx * dx + dy * dy <= domet * domet;
                           });

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;

    return 0;
}