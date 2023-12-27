#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

// int main() {
//     const char* testCases[] = {
//         "a", "c", "0", "-42", "42", "0.0f", "-4.2f", "4.2f", 
//         "-inff", "+inff", "nanf", "0.0", "-4.2", "4.2", "-inf", "+inf", "nan"
//     };
//     for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
//         std::cout << "Testing " << testCases[i] << std::endl;
//         ScalarConverter::convert(testCases[i]);
//         std::cout << std::endl;
//     }
//     return 0;
// }
// 