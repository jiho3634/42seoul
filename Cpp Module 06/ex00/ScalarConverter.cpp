#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>  // std::setprecision 함수를 사용하여 출력 형식을 지정
#include <cctype>   // std::isprint, std::isdigit
#include <sstream>  // std::istringstream
#include <limits>   // std::numeric_limits

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    std::istringstream iss(literal);
    /*literal에 저장된 문자열을 내부 버퍼로 복사하며, 
    이후 iss를 통해 그 내용을 다양한 데이터 타입으로 읽을 수 있습니다.
    std::istringstream은 주로 문자열로부터 원시 데이터 타입(예: int, double, float 등)을 파싱하는 데 사용됩니다. 
    >> 연산자를 사용하여 이 스트림으로부터 데이터를 읽을 수 있으며, 스트림이 자동으로 적절한 타입으로 데이터를 변환합니다.*/
    double parsedDouble;

    // 특수한 부동 소수점 값 확인 및 처리
    if (literal == "nan" || literal == "nanf") {    // 'Not a Number' (NaN)
        // parsedDouble = 0.0 / 0.0; // 0으로 나누어 NaN을 생성하는 시도
        parsedDouble = std::numeric_limits<double>::quiet_NaN();
    } else if (literal == "-inf" || literal == "-inff") {
        parsedDouble = -std::numeric_limits<double>::infinity();
    } else if (literal == "+inf" || literal == "+inff" || \
                literal == "inf" || literal == "inff") {
        parsedDouble = std::numeric_limits<double>::infinity();
    } else {
        // 문자 리터럴 처리
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
            char charValue = literal[0];
            std::cout << "char: " << charValue << std::endl;
            int intValue = static_cast<int>(charValue);
            std::cout << "int: " << intValue << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(intValue) << std::endl;
            std::cout << std::defaultfloat;
            return;
        }
        // 일반적인 숫자 또는 문자 리터럴 처리
        std::string modifiedLiteral = literal;
        if (literal.length() > 1 && literal.back() == 'f') {
            modifiedLiteral.pop_back();  // 'f' 문자 제거
        }

        std::istringstream iss(modifiedLiteral);
        if (!(iss >> parsedDouble)) {
            // 문자열로부터 double 값으로의 변환을 시도, 
            //실패하면, 스트림의 상태 플래그 중 하나가 설정되고 연산은 false와 같이 평가됩니다.
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    //std::istringstream은 double 타입으로의 변환에 최적화되어 있으며, 
    //다른 타입으로의 직접 변환은 별도의 접근 방법이 필요할 수 있습니다.

    // char 변환
    char charValue = static_cast<char>(parsedDouble);
    if (std::isprint(charValue)) {
        std::cout << "char: " << charValue << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    // int 변환
    int intValue = static_cast<int>(parsedDouble);
    std::cout << "int: " << intValue << std::endl;

    // float 변환
    float floatValue = static_cast<float>(parsedDouble);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << std::defaultfloat;

    // double 변환
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << parsedDouble << std::endl;
    std::cout << std::defaultfloat;
}
