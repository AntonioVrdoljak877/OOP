
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Money {
private:
    int cents; // Ukupan iznos u centima

public:
    // Konstruktor
    Money(int euros = 0, int centi = 0) {
        cents = euros * 100 + centi;
    }

    // Operator +=
    Money& operator+=(const Money& other) {
        cents += other.cents;
        return *this;
    }

    // Operator +
    Money operator+(const Money& other) const {
        return Money(0, cents + other.cents);
    }

    // Operator <
    bool operator<(const Money& other) const {
        return cents < other.cents;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Money& m) {
        out << m.cents / 100 << '.'
            << setw(2) << setfill('0')
            << abs(m.cents % 100) << " EUR";

        return out;
    }

    // Operator >>
    friend istream& operator>>(istream& in, Money& m) {
        int euros, centi;
        char znak;

        in >> euros >> znak >> centi;

        if (!in) {
            return in;
        }

        if (znak != '.') {
            in.setstate(ios::failbit);
            return in;
        }

        m = Money(euros, centi);

        return in;
    }
};
