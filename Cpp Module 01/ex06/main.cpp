#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
        return 1;
    }

    std::string logLevel = argv[1];
    Harl harl;

    harl.filterAndDisplay(logLevel);

    return 0;
}
