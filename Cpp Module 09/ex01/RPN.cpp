#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <cstdlib>

double performOperation(const std::string& op, double a, double b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

double calculateRPN(const std::string& expression) {
    std::stack<double> stack;
    std::stringstream ss(expression);
    std::string token;

    //expression을 공백 기준으로 토큰화
    while (ss >> token) {
        //첫 문자가 숫자이거나 첫 문자가 '-'이고 두 번째 문자가 숫자인 경우
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            char* end;  //end는 변환 후 처리되지 않은 나머지 문자열의 시작 부분을 가리키는 포인터.
            double num = std::strtod(token.c_str(), &end);  //숫자로 시작하지 않는 경우, num은 0.0으로 설정
            //함수 원형: double strtod(const char* str, char** endptr);
            if (*end != 0) {    //변환되지 않은 문자가 남아있는 경우
                throw std::runtime_error("Error");
            }
            stack.push(num);
        } else {
            if (stack.size() < 2) { // 두 개의 피연산자가 필요
                throw std::runtime_error("Error");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));
        }
    }

    // 모든 토큰 처리 후 스택에 하나의 요소만 남아 있어야 함. 최종 계산 결과.
    if (stack.size() != 1) {
        throw std::runtime_error("Error");
    }

    return stack.top();
}