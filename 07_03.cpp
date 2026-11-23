#include <iostream>

class IntStack {
private:
    int* niz;
    int brojElemenata;
    int kapacitet;

public:
    IntStack(int pocetniKapacitet = 2) {
        kapacitet = pocetniKapacitet;
        brojElemenata = 0;
        niz = new int[kapacitet];
    }

    IntStack(const IntStack& drugi) {
        std::cout << "copy konstruktor" << std::endl;
        kapacitet = drugi.kapacitet;
        brojElemenata = drugi.brojElemenata;
        niz = new int[kapacitet];
        for (int i = 0; i < brojElemenata; i++) {
            niz[i] = drugi.niz[i];
        }
    }

    IntStack& operator=(const IntStack& drugi) {
        std::cout << "copy assignment" << std::endl;
        if (this == &drugi) {
            return *this;
        }

        int* noviNiz = new int[drugi.kapacitet];
        for (int i = 0; i < drugi.brojElemenata; i++) {
            noviNiz[i] = drugi.niz[i];
        }

        delete[] niz;
        niz = noviNiz;
        kapacitet = drugi.kapacitet;
        brojElemenata = drugi.brojElemenata;
        return *this;
    }

    IntStack(IntStack&& drugi) noexcept {
        std::cout << "move konstruktor" << std::endl;
        niz = drugi.niz;
        brojElemenata = drugi.brojElemenata;
        kapacitet = drugi.kapacitet;

        drugi.niz = nullptr;
        drugi.brojElemenata = 0;
        drugi.kapacitet = 0;
    }

    IntStack& operator=(IntStack&& drugi) noexcept {
        std::cout << "move assignment" << std::endl;
        if (this == &drugi) {
            return *this;
        }

        delete[] niz;

        niz = drugi.niz;
        brojElemenata = drugi.brojElemenata;
        kapacitet = drugi.kapacitet;

        drugi.niz = nullptr;
        drugi.brojElemenata = 0;
        drugi.kapacitet = 0;
        return *this;
    }

    ~IntStack() {
        delete[] niz;
    }

    void push(int x) {
        if (brojElemenata == kapacitet) {
            kapacitet *= 2;
            int* noviNiz = new int[kapacitet];
            for (int i = 0; i < brojElemenata; i++) {
                noviNiz[i] = niz[i];
            }
            delete[] niz;
            niz = noviNiz;
        }
        niz[brojElemenata] = x;
        brojElemenata++;
    }

    void pop() {
        if (!empty()) {
            --brojElemenata;
        }
    }

    int top() const {
        return niz[brojElemenata - 1];
    }

    bool empty() const {
        return brojElemenata == 0;
    }

    int size() const {
        return brojElemenata;
    }

    int capacity() const {
        return kapacitet;
    }
};