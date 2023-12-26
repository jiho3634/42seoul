#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Form 클래스 생성자와 예외 케이스 테스트
    std::cout << "\nTesting Form constructor and exceptions:" << std::endl;

    // 유효한 등급으로 Form 객체 생성
    try {
        Form validForm("\nValidForm", 50, 25);
        std::cout << validForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "\nException: " << e.what() << std::endl;
    }

    // 너무 높은 등급으로 Form 객체 생성 (예외 발생 예상)
    try {
        Form highGradeForm("HighGradeForm", 0, 25);
        std::cout << highGradeForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 너무 낮은 등급으로 Form 객체 생성 (예외 발생 예상)
    try {
        Form lowGradeForm("LowGradeForm", 151, 25);
        std::cout << lowGradeForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Form 객체 사용 예제 및 예외 케이스 테스트
    std::cout << "\nTesting Form usage and exception handling:" << std::endl;

    try {
        Bureaucrat harry("Harry", 5);
        Form hogwartsForm("HogwartsForm", 10, 5);

        std::cout << harry << std::endl;
        std::cout << hogwartsForm << std::endl;

        hogwartsForm.beSigned(harry);
        std::cout << "After signing: " << std::endl;
        std::cout << hogwartsForm << std::endl;

        // 예외 케이스: 너무 낮은 등급의 Bureaucrat가 Form에 서명 시도
        Bureaucrat lowRankBureaucrat("Dobby", 150);
        hogwartsForm.beSigned(lowRankBureaucrat);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // signForm 메소드에 대한 추가 테스트
    std::cout << "\nTesting signForm method:" << std::endl;

    try {
        Bureaucrat highRankBureaucrat("Alice", 5);
        Bureaucrat lowRankBureaucrat("Bob", 150);
        Form testForm("TestForm", 100, 50);

        std::cout << highRankBureaucrat << std::endl;
        std::cout << lowRankBureaucrat << std::endl;
        std::cout << testForm << std::endl;

        highRankBureaucrat.signForm(testForm); // 성공해야 함
        lowRankBureaucrat.signForm(testForm); // 실패하고 예외를 던져야 함
    } catch (std::exception& e) {
        std::cerr << "예외 포착: " << e.what() << std::endl; // 예외 처리
    }

    return 0;
}
