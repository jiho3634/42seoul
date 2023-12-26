#include "ScalarConverter.hpp"
#include <iostream>
#include <exception>
#include <iomanip>//std::setprecision 함수를 사용하여 출력 형식을 지정
#include <cmath>//std::stod, std::stof 문자열을 부동 소수점 수(double, float)로 변환
#include <cctype>//std::isprint, std::isdigit

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {
}


void ScalarConverter::convert(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char charValue = literal[0];
        std::cout << "char: " << charValue << std::endl;
        int asciiValue = static_cast<int>(charValue);
        std::cout << "int: " << asciiValue << std::endl;
        std::cout << std::fixed << std::setprecision(1);//부동소수점을 고정소수점 한자리 수로 설정
        std::cout << "float: " << static_cast<float>(asciiValue) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(asciiValue) << std::endl;
        std::cout << std::defaultfloat;//부동소수점 설정 초기점
    } 
    else {
        try {
            double parsedDouble = std::stod(literal);
            char charValue = static_cast<char>(parsedDouble);
            if (std::isprint(charValue)) {
                std::cout << "char: " << charValue << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        } catch (std::exception& e) {
            std::cout << "char: impossible" << std::endl;
        }

        try {
            int intValue = static_cast<int>(std::stod(literal));
            std::cout << "int: " << intValue << std::endl;
        } catch (std::exception& e) {
            std::cout << "int: impossible" << std::endl;
        }

        try {
            float floatValue = std::stof(literal);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << floatValue << "f" << std::endl;
            std::cout << std::defaultfloat;
        } catch (std::exception& e) {
            std::cout << "float: impossible" << std::endl;
        }

        try {
            double doubleValue = std::stod(literal);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << doubleValue << std::endl;
            std::cout << std::defaultfloat;
        } catch (std::exception& e) {
            std::cout << "double: impossible" << std::endl;
        }
    }
}
