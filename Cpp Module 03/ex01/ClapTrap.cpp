#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
 : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
 : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap " << name << " assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        hitPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    if (hitPoints < amount)
        hitPoints = 0;
    else
        hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0) {
        hitPoints--;
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        hitPoints += amount;
    }
}
