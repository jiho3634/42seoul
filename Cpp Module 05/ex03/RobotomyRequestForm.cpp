#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises... Bzzzz... Bzzzz..." << std::endl;
    if (std::rand() % 2) { //  0부터 RAND_MAX까지의 범위 내에서 정수 값을 반환
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}
