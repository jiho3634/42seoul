#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;

    try {
        // 정상적인 폼 생성 테스트
        AForm* form1 = intern.makeForm("shrubbery creation", "Form1");
        std::cout << *form1 << std::endl;
        delete form1; // 생성된 폼 객체를 삭제

        AForm* form2 = intern.makeForm("robotomy request", "Form2");
        std::cout << *form2 << std::endl;
        delete form2; // 생성된 폼 객체를 삭제

        AForm* form3 = intern.makeForm("presidential pardon", "Form3");
        std::cout << *form3 << std::endl;
        delete form3; // 생성된 폼 객체를 삭제

        // 알 수 없는 폼 이름에 대한 테스트
        AForm* form4 = intern.makeForm("unknown form", "Form4");
        if (form4) {
            std::cout << *form4 << std::endl;
            delete form4;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
