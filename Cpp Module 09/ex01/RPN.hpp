#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string& expression);
double performOperation(const std::string& op, double a, double b);
double calculateRPN(const std::string& expression);

#endif
