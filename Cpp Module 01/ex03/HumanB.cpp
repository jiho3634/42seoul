#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& newWeapon) {
    weapon = &newWeapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " is unarmed." << std::endl;
    }
}

