#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "";
    }
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = src._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    }
    return "";
}
