#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Board {
private:
    char* niz;
    int r;
    int c;

public:
    Board(int rows, int cols, char rub) {
        assert(rows >= 2 && cols >= 2);
        r = rows;
        c = cols;
        niz = new char[r * c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    niz[i * c + j] = rub;
                } else {
                    niz[i * c + j] = ' ';
                }
            }
        }
    }

    Board(const Board& b) {
        r = b.r;
        c = b.c;
        niz = new char[r * c];
        for (int i = 0; i < r * c; i++) {
            niz[i] = b.niz[i];
        }
    }

    ~Board() {
        delete[] niz;
    }

    void set(int i, int j, char ch) {
        if (i > 0 && i < r - 1 && j > 0 && j < c - 1) {
            niz[i * c + j] = ch;
        }
    }

    char get(int i, int j) const {
        assert(i >= 0 && i < r && j >= 0 && j < c);
        return niz[i * c + j];
    }

    int rows() const { return r; }
    int cols() const { return c; }

    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << niz[i * c + j];
            }
            std::cout << std::endl;
        }
    }
};

class Enemy {
private:
    std::string name;
    int x;
    int y;
    int health;

public:
    Enemy(std::string n, int x, int y, int h = 100)
        : name(n), x(x), y(y), health(h) {}

    std::string get_name() const { return name; }
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_health() const { return health; }

    bool is_alive() const {
        return health > 0;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void take_damage(int d) {
        health -= d;
        if (health < 0) {
            health = 0;
        }
    }
};

class Level {
private:
    int rows;
    int cols;
    std::vector<Enemy> enemies;

public:
    Level(int r, int c) : rows(r), cols(c) {}

    bool add(Enemy e) {
        if (e.get_x() < 0 || e.get_x() >= cols ||
            e.get_y() < 0 || e.get_y() >= rows) {
            return false;
        }
        enemies.push_back(e);
        return true;
    }

    void step(int dx, int dy) {
        for (Enemy& e : enemies) {
            int nx = e.get_x() + dx;
            int ny = e.get_y() + dy;
            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows) {
                e.move(dx, dy);
            }
        }
    }

    void print() const {
        for (const Enemy& e : enemies) {
            std::cout << e.get_name() << " (" << e.get_x() << ", "
                      << e.get_y() << ") " << e.get_health() << std::endl;
        }
    }

    void draw() const {
        Board b(rows + 2, cols + 2, '#');
        for (const Enemy& e : enemies) {
            // y = redak, x = stupac; unutarnje polje Boarda počinje od 1
            b.set(e.get_y() + 1, e.get_x() + 1, e.get_name()[0]);
        }
        b.print();
    }
};