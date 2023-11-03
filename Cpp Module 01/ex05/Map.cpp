#include "Map.hpp"
#include "Harl.hpp"

Map::Map() : size(0) {}

void Map::set(const std::string& key, void (Harl::*func)() const) {
    if (size < 4) {
        keys[size] = key;
        functions[size] = func;
        size++;
    }
}

void (Harl::*Map::get(const std::string& key))() const {
    for (int i = 0; i < size; ++i) {
        if (keys[i] == key) {
            return functions[i];
        }
    }
    return NULL;
}
