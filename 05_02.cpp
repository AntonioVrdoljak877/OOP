#include <iostream>
#include <string>

class Clip {
    int start;
    int end;
    int length;
    std::string name;
    const int max_length;

public:
    Clip(const std::string& n, int s, int e)
        : start(s), end(e), length(e - s), name(n), max_length(600)
    {
    }

    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main() {
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
}