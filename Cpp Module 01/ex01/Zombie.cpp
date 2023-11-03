#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() :  _name("Default Zombie") {
    std::cout << "Default Zombie is born." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie named " << _name << " is born." << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	std::cout << "Changing name from " << _name << " to " << name << std::endl;
    _name = name;
}
