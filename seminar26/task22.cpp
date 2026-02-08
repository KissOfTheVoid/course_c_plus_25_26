/*
    Works with string library
    A playable character with stats
*/

#include <iostream>
#include <string>

class Character {
public:
    struct Stats {
        int hp;
        int attack;
        int defense;
    };

private:
    std::string name;
    Stats stats;

public:
    Character(const std::string& name_, int hp, int attack, int defense)
        : name(name_), stats{hp, attack, defense} {}

    Character(const Character& other)
        : name(other.name), stats(other.stats) {}

    Character& operator=(const Character& other) {
        if (this == &other) {
            return *this;
        }
        this->name  = other.name;
        this->stats = other.stats;
        return *this;
    }

    void hit(Character& target) {
        int damage = this->stats.attack - target.stats.defense;
        if (damage < 0) damage = 0;
        target.stats.hp -= damage;
        if (target.stats.hp < 0) target.stats.hp = 0;
    }

    void heal(int amount) {
        this->stats.hp += amount;
    }

    void print() const {
        std::cout << "Character: " << name << " | HP: " << stats.hp << " | ATK: " << stats.attack << " | DEF: " << stats.defense << '\n';
    }
};

int main() {
    Character a("Princess of archers", 1000, 1500, 5);
    Character b("Knight", 1140, 80, 20);

    a.hit(b);
    b.print();

    b.heal(105);
    b.print();

    Character c = a;
    c.print();
    c = b;
    c.print();
    /*
    Character: Knight | HP: 0 | ATK: 80 | DEF: 20
    Character: Knight | HP: 105 | ATK: 80 | DEF: 20
    Character: Princess of archers | HP: 1000 | ATK: 1500 | DEF: 5
    Character: Knight | HP: 105 | ATK: 80 | DEF: 20
    */
    return 0;
}
