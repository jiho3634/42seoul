#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form);
    void executeForm(AForm const &form);    //  추가된 함수

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
