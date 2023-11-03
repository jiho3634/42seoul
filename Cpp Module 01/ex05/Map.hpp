#ifndef MAP_HPP
#define MAP_HPP

#include <string>

class Harl;

class Map {
public:
    Map();
    void set(const std::string& key, void (Harl::*func)() const);
    void (Harl::*get(const std::string& key))() const;

private:
    std::string keys[4];
    void (Harl::*functions[4])()const;
    int size;
};

#endif
