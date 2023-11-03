#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int numberOfZombies = 5;
    std::string zombieName = "Zombie";

    Zombie* zombieGroup = zombieHorde(numberOfZombies, zombieName);

    for (int i = 0; i < numberOfZombies; i++) {
        zombieGroup[i].announce();
    }

    delete[] zombieGroup;

    return 0;
}
