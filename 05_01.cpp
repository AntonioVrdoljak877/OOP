#include <iostream>
#include <cassert>

class Volume
{
private:
    int level;
    int prosli_level;

    static int limit(int l)
    {
        if (l < 0)
        {
            return 0;
        }
        if (l > 100)
        {
            return 100;
        }
        return l;
    }

    bool valid() const
    {
        return (level >= 0) && (level <= 100);
    }

public:
    Volume(int l) : level(limit(l)), prosli_level(l)
    {
        assert(valid());
    }

    Volume() : Volume(50) {}

    void up(int step = 10)
    {
        level = limit(level + step);
        assert(valid());
    }

    void down(int step = 10)
    {
        level = limit(level - step);
        assert(valid());
    }

    void mute()
    {
        if (level != 0)
        {
            prosli_level = level;
        }
        level = 0;
        assert(valid());
    }

    void unmute()
    {
        level = prosli_level;
        assert(valid());
    }

    int getLevel()
    {
        return level;
    }
};



int main()
{


    Volume v;
    std::cout << v.getLevel() << '\n';
    v.up();
    v.up(60);
    std::cout << v.getLevel() << '\n';
    v.mute();
    std::cout << v.getLevel() << '\n';
    v.unmute();
    std::cout << v.getLevel() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.getLevel() << '\n';
    return 0;


}
