#include "FragTrap.hpp"

int main() {
    FragTrap ironMan("IronMan");
    
    ironMan.attack("Thanos");
    ironMan.takeDamage(10);
    ironMan.beRepaired(10);
    ironMan.highFivesGuys();

    return 0;
}
