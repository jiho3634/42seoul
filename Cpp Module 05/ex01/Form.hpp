#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);


    // getter 메소드
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    // 폼 서명
    void beSigned(const Bureaucrat& bureaucrat);

    // 예외 클래스
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
