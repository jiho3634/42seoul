#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include "Map.hpp"

class Harl {
public:
    Harl();
    void complain(const std::string level);

private:
    Map complaintsMap;

    void debug() const;
    void info() const;
    void warning() const;
    void error() const;
};

#endif
