#include "Harl.hpp"
#include "Map.hpp"
#include <iostream>

Harl::Harl() {
    complaintsMap.set("DEBUG", &Harl::debug);
    complaintsMap.set("INFO", &Harl::info);
    complaintsMap.set("WARNING", &Harl::warning);
    complaintsMap.set("ERROR", &Harl::error);
}

void Harl::complain(const std::string level) {
    void (Harl::*func)() const;

    func = complaintsMap.get(level);

    if (func) {
        (this->*func)();
    } else {
        std::cout << "Unknown complaint level: " << level << std::endl;
    }
}

void Harl::debug() const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
