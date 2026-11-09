class Coin {
    int value;
    static int count;

public:
    Coin(int v) : value(v) {
        ++count;
    }

    ~Coin() {
        --count;
    }

    static int remaining() {
        return count;
    }

    int getValue() const {
        return value;
    }
};

int Coin::count = 0;