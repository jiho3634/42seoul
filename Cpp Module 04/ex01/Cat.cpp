#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& src) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &src) {
        _type = src._type;
        // Note that Brain is copied automatically by Animal's assignment operator
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
