#include <iostream>

typedef std::string str_t;

class Character {
private:
    str_t name;
    int health = 100;
public:
    Character(str_t characterName) {
        name = characterName;
    }
    void get_attacked(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        std::cout << name << " has been attacked! Health is now: " << health << '\n';
    }
    void attack(Character &target, int damage = 10) {
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        target.get_attacked(damage);
    }
    str_t get_name() {
        return name;
    }
    int get_health() {
        return health;
    }
};