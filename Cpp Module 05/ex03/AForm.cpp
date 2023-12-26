#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(false), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {
}

AForm::~AForm() {
}

AForm& AForm::operator=(const AForm&) {
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}
bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm Name: " << form.getName()
       << "\nSigned: " << (form.getIsSigned() ? "Yes" : "No")
       << "\nGrade Required to Sign: " << form.getGradeRequiredToSign()
       << "\nGrade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
