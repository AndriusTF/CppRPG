#include <iostream>
#include <vector>

typedef std::string str_t;
template<typename T>
using vec_t = std::vector<T>;


class Object {
private:
    str_t name;
    int value;
public:
    Object(str_t objectName, int objectValue = 1) {
        name = objectName;
        value = objectValue;
    }
    str_t get_name() const {
        return name;
    }
    int get_value() const {
        return value;
    }
protected:
    void set_value(int newValue) {
        value = newValue;
    }
};

class Weapon : public Object {
private:
    int damage;
public:
    Weapon(str_t weaponName, int weaponDamage)
        : Object(weaponName, 1), damage(weaponDamage) {
    }
    int get_damage() const {
        return damage;
    }
};



class Character {
private:
    str_t name;
    int health = 100;
    vec_t<Object*> inventory; // Example of using the template alias
    Weapon *equippedWeapon = nullptr; // Pointer to a Weapon object
public:
    Character(str_t characterName) {
        name = characterName;
    }
    ~Character() {
        for (Object* obj : inventory) {
            std::cout << name << " is cleaning up " << obj->get_name() << " from inventory.\n";
            delete obj; // Clean up dynamically allocated objects
        }
        if (equippedWeapon) {
            std::cout << name << " is cleaning up " << equippedWeapon->get_name() << " from inventory.\n";
            delete equippedWeapon; // Clean up the equipped weapon if it exists
        }
    }
    void get_attacked(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        std::cout << name << " has been attacked! Health is now: " << health << '\n';
    }
    void attack(Character &target, int damage = 10) {
        if (equippedWeapon) {
            damage = equippedWeapon->get_damage();
        }
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        target.get_attacked(damage);
    }
    str_t get_name() {
        return name;
    }
    int get_health() {
        return health;
    }
    void add_to_inventory(Object *object) {
        inventory.push_back(object);
        std::cout << name << " added " << object->get_name() << " to inventory.\n";
    }
    void equip_weapon(Weapon *weapon) {
        if (equippedWeapon) {
            std::cout << name << " unequipped " << equippedWeapon->get_name() << ".\n";
            delete equippedWeapon; // Clean up the previous weapon
        }
        equippedWeapon = weapon;
        std::cout << name << " equipped " << weapon->get_name() << " with damage " << weapon->get_damage() << ".\n";
    }
};