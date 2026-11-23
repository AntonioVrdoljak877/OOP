
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Enemy
{
protected:
    std::string name;
    int health;

public:
    Enemy(std::string n, int h) : name(n), health(h) {}

    virtual void take_damage(int d)
    {
        health -= d;
        std::cout << name << " prima " << d << " stete. "
                  << "Zdravlje: " << health << std::endl;
    }

    bool is_dead() const
    {
        return (health<=0);
    }

    virtual ~Enemy()
    {
        std::cout << name << " izbrisan" << std::endl;
    }
};

class Goblin : public Enemy
{
public:
    Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy
{
private:
    int hits=0;

public:
    Bat() : Enemy("Bat", 15) {}

    void take_damage(int d) override
    {
        hits++;

        if (hits % 2 == 0)
        {
            std::cout << name << " izbjegava udarac!" << std::endl;
        }
        else
        {
            health -= d;
            std::cout << name << " prima " << d
                      << " stete. Zdravlje: " << health << std::endl;
        }
    }
};

class Ghost : public Enemy
{
public:
    Ghost() : Enemy("Ghost", 30) {}

    void take_damage(int d) override
    {
        int damage = d / 2;
        health -= damage;

        std::cout << name << " prima " << damage
             << " stete. Zdravlje: " << health << std::endl;
    }
};

class Level
{
private:
    std::vector<Enemy*> enemies;

public:
    Level() = default;


    Level(const Level&) = delete;
    Level& operator=(const Level&) = delete;

    void add_enemy(Enemy* e)
    {
        enemies.push_back(e);
    }


    void explode(int d)
    {
        for (auto e : enemies)
        {
            e->take_damage(d);
        }


        auto it = remove_if(
                      enemies.begin(),
                      enemies.end(),
                      [](Enemy* e)
        {
            if (e->is_dead())
            {
                delete e;
                return true;
            }
            return false;
        }
                  );

        enemies.erase(it, enemies.end());
    }


    ~Level()
    {
        for (Enemy* e : enemies)
        {
            delete e;
        }
    }
};

int main()
{
    Level level;

    level.add_enemy(new Goblin());
    level.add_enemy(new Bat());
    level.add_enemy(new Ghost());

    level.explode(10);
    level.explode(10);
    level.explode(10);

    return 0;
}

