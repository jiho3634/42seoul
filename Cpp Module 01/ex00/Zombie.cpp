#include "Zombie.hpp"

Zombie::Zombie( void ) : name("Unnamed Zombie") {
	std::cout << name << " has been constructed." << std::endl;
}

Zombie::Zombie( std::string name) : name(name) {
	std::cout << name << " has been constructed." << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << name << " has been destroyed." << std::endl;
}
