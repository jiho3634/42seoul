#include "ScavTrap.hpp"

int main() {
    ScavTrap ironMan("IronMan");
    
    ironMan.attack("Thanos");
    ironMan.takeDamage(50);
    ironMan.beRepaired(30);
    ironMan.guardGate();
    
    return 0;
}
