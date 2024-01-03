#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    std::string vectorSortTime = sortVector(argc, argv);
    std::string listSortTime = sortList(argc, argv);

    std::cout << vectorSortTime << std::endl;
    std::cout << listSortTime << std::endl;

    return 0;
}
