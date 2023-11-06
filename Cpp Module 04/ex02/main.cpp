#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

     Animal* animals[10];
    for (int index = 0; index < 5; ++index) {
        animals[index] = new Dog();
    }
    for (int index = 5; index < 10; ++index) {
        animals[index] = new Cat();
    }
    Animal* copiedAnimals[10];
    for (int index = 0; index < 10; ++index) {
        copiedAnimals[index] = animals[index];
    }
    for (int index = 0; index < 10; ++index) {
        delete animals[index];
        delete copiedAnimals[index];
    }
    return 0;
}
