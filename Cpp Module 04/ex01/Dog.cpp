#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &src) {
        _type = src._type;
        // Note that Brain is copied automatically by Animal's assignment operator
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
