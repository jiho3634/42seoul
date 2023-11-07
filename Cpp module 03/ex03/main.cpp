#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("OptimusPrime");
    diamond.attack("Decepticon");
    diamond.whoAmI();
    diamond.takeDamage(10);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    return 0;
}
