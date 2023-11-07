#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& src);
    Animal& operator=(const Animal& src);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string _type;

private:
    Brain* _brain;
};

#endif
