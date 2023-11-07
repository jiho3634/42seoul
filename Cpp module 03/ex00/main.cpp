#include "ClapTrap.hpp"

int main() {
    ClapTrap clap;

    clap.attack("jihokim2");
    clap.takeDamage(10);
    clap.beRepaired(10);

    ClapTrap clap1("JIHO");
    ClapTrap clap2("KIM2");

    clap1.attack("KIM2");
    clap1.takeDamage(20);
    clap1.beRepaired(10);

    clap2.attack("JIHO");
    clap2.takeDamage(30);
    clap2.beRepaired(15);

    clap = clap2;
    clap.attack("jihokim2"); 
    return 0;
}
