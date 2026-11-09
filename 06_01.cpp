#include <iostream>

class IntStack
{
private:
    int* niz;
    int brojElemenata;
    int kapacitet;

public:

    IntStack(int pocetniKapacitet = 2)
    {
        this->kapacitet=pocetniKapacitet;
        brojElemenata=0;
        niz = new int[kapacitet];
    }

    ~IntStack()
    {
        delete[] niz;
    }

    IntStack(const IntStack& drugi)
    {
        kapacitet = drugi.kapacitet;
        brojElemenata = drugi.brojElemenata;
        niz = new int[kapacitet];

        for (int i=0;i<brojElemenata; i++)
        {
            niz[i] = drugi.niz[i];
        }
    }

    void push(int x)
    {
        if (brojElemenata == kapacitet)
        {
            kapacitet *=2;
            int* noviNiz = new int[kapacitet];

            for (int i = 0; i < brojElemenata; ++i)
            {
                noviNiz[i] = niz[i];
            }

            delete[] niz;
            niz = noviNiz;
        }

        niz[brojElemenata] = x;
        brojElemenata++;
    }

    void pop()
    {
        if (!empty())
        {
            --brojElemenata;
        }
    }

    int top() const
    {
        return niz[brojElemenata-1];
    }

    bool empty() const
    {
        return brojElemenata == 0;
    }

    int size() const
    {

        return brojElemenata;
    }

    int capacity() const
    {

        return kapacitet;
    }
};

int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);

    std::cout <<s.size()<< ' '<<s.capacity()<<' '<<s.top()<<'\n';



    IntStack c = s;
    c.pop();
    c.push(99);

    std::cout<<s.top()<<' '<<c.top()<< '\n';

    while (!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }

    std::cout << '\n';
    return 0;
}
