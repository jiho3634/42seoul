#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
ClapTrap("_clap_name")
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : 
ClapTrap(name + "_clap_name"), name(name)
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "DiamondTrap " << this->name << " assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::print() {
    std::cout << name << std::endl;
    std::cout << hitPoints << std::endl;
    std::cout << energyPoints << std::endl;
    std::cout << attackDamage << std::endl;
}