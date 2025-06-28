#include <iostream>
#include "characters.hpp"

typedef std::string str_t;

int main()
{
    std::cout << "Welcome to CppRPG!" << '\n';
    std::cout << "==================" << '\n';

    Character hero("Hero");
    Character monster("Monster");
    Weapon *sword = new Weapon("Sword", 20);

    hero.equip_weapon(sword);

    monster.attack(hero);
    hero.attack(monster);

    std::cout << monster.get_name() << " is angry!" << '\n';
    monster.attack(hero, 90);
    
    return 0;
}
