#include "Span.hpp"
#include <iostream>

int main() {
    Span span(5);

    try {
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        span.addNumber(1);

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        span.addNumber(2);
        span.addNumber(3);
        span.addNumber(4);
        span.addNumber(5);

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        span.addNumber(6);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
