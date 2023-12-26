#include "Bureaucrat.hpp"

int main() {
    // 기본 생성자 및 출력 테스트
    Bureaucrat harry("Harry", 50);
    std::cout << harry << std::endl;

    // 복사 생성자 및 출력 테스트
    Bureaucrat ron(harry);
    std::cout << ron << std::endl;

    // 복사 할당 연산자 테스트
    Bureaucrat hermione("Hermione", 75);
    std::cout << "Before assignment: " << hermione << std::endl;
    hermione = harry; // 해리 포터로 복사 할당
    std::cout << "After assignment: " << hermione << std::endl;

    // 예외 처리 테스트: 너무 높은 등급
    try {
        Bureaucrat dumbledore("Dumbledore", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 예외 처리 테스트: 너무 낮은 등급
    try {
        Bureaucrat dobby("Dobby", 151);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 등급 증가 및 예외 처리 테스트
    try {
        Bureaucrat snape("Snape", 2);
        std::cout << snape << std::endl;
        snape.incrementGrade(); // 등급 증가
        std::cout << snape << std::endl;
        snape.incrementGrade(); // 등급 증가
        std::cout << snape << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 등급 감소 및 예외 처리 테스트
    try {
        Bureaucrat snape("Snape", 2);
        std::cout << snape << std::endl;
        snape.decrementGrade(); // 등급 감소
        std::cout << snape << std::endl;
        snape.decrementGrade(); // 등급 감소
        std::cout << snape << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
