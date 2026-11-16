
#include <iostream>
using namespace std;

class Ticket {
private:
    int broj;
    static int sljedeci;

public:
    Ticket() {
        broj = ++sljedeci;
    }

    Ticket(const Ticket& t) = delete;

    int get_broj() const {
        return broj;
    }
};

int Ticket::sljedeci = 0;

void print(const Ticket& t) {
    cout << t.get_broj() << endl;
}

int main() {
    Ticket t1;
    Ticket t2;
    Ticket t3;

    print(t1);
    print(t2);
    print(t3);

    return 0;
}
