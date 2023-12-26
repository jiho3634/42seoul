#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>    //  std::exception

class Bureaucrat {
private:
    const std::string name;
    int grade;  //  from 1(highest) to 150(lowest)
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();   // 예외에 대한 설명 문자열을 반환
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
