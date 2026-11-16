
#include <iostream>
#include <cassert>
using namespace std;

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

    int rows() const {
        return r;
    }

    int cols() const {
        return c;
    }

    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << niz[i * c + j];
            }
            cout << endl;
        }
    }
};

int main() {
    Board b(5, 8, '#');

    b.set(1, 1, 'A');
    b.set(2, 3, 'B');
    b.set(3, 5, 'C');

    Board b2 = b;

    b.print();
    cout << endl;
    b2.print();

    return 0;
}
