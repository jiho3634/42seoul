#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << ' ';
}

int main() {
    int arrayInt[] = {1, 2, 3, 4, 5};
    std::string arrayString[] = {"jihokim2", "wanna", "finish", "C++"};

    std::cout << "\nInteger array" << std::endl;
    iter(arrayInt, 5, printElement<int>);

    std::cout << "\nString array" << std::endl;
    iter(arrayString, 4, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
