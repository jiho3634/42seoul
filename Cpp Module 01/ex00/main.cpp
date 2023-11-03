#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void ) {
	Zombie	Roki("Roki");
	Roki.announce();
	randomChump("Torr");
	Zombie* Odin = newZombie("Odin");
	Odin->announce();
	delete Odin;
	return 0;
}
