#include "Harl.hpp"
#include <iostream>

void Harl::filterAndDisplay(const std::string& logLevel) const {
    std::string levels[] = { "INFO", "WARNING", "ERROR", "CRITICAL" };

    int selectedLevel = -1;

    for (int i = 0; i < 4; i++) {
        if (logLevel == levels[i]) {
            selectedLevel = i;
            break;
        }
    }

    if (selectedLevel == -1) {
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    for (int i = selectedLevel; i < 4; i++) {
        switch (i) {
            case 0:
                std::cout << "[ INFO ]" << std::endl;
                std::cout << "I am not sure how tired I am today..." << std::endl;
                break;
            case 1:
                std::cout << "[ WARNING ]" << std::endl;
                std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
                std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
                break;
            case 2:
                std::cout << "[ ERROR ]" << std::endl;
                std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
                break;
            case 3:
                std::cout << "[ CRITICAL ]" << std::endl;
                std::cout << "The server is on fire! Call the IT department immediately!" << std::endl;
                break;
        }
    }
}
