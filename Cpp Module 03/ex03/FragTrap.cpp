#include "FragTrap.hpp"

FragTrap::FragTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "ScavTrap has been created with default values!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << name << " copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints > 0) {
        std::cout << "FragTrap " << name << " attacks " << target 
        << ", causing " << attackDamage << " points of damage!" << std::endl;
        hitPoints--;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
