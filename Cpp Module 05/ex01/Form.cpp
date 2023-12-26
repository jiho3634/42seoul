#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(false), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {
}

Form::~Form() {
}

Form& Form::operator=(const Form&) {
    return *this;
}

const std::string& Form::getName() const {
    return name;
}
bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form Name: " << form.getName()
       << "\nSigned: " << (form.getIsSigned() ? "Yes" : "No")
       << "\nGrade Required to Sign: " << form.getGradeRequiredToSign()
       << "\nGrade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
