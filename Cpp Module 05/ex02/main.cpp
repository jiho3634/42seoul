#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::srand(std::time(NULL)); // 시드 초기화
    try {
        Bureaucrat michael("Michael", 2);
        Bureaucrat lebron("LeBron", 149);
        ShrubberyCreationForm curry("Curry");
        RobotomyRequestForm durant("Durant");
        PresidentialPardonForm kyrie("Kyrie");

        std::cout << michael << std::endl;
        std::cout << lebron << std::endl;

        michael.executeForm(curry);
        michael.executeForm(durant);
        michael.executeForm(kyrie);

        curry.beSigned(michael);
        durant.beSigned(michael);
        kyrie.beSigned(michael);

        michael.executeForm(curry);
        michael.executeForm(durant);
        michael.executeForm(kyrie);

        lebron.executeForm(curry);
        lebron.executeForm(durant);
        lebron.executeForm(kyrie);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
