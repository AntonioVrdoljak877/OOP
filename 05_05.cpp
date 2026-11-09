#include <string>
#include <iostream>

class Ticket {
    std::string concert;
    int number;
    static int counter;

public:
    Ticket(const std::string& c) : concert(c), number(++counter) {}

    static int issued() {
        return counter;
    }

    void print() const {
        std::cout << concert << " #" << number << "\n";
    }
};

int Ticket::counter = 0;