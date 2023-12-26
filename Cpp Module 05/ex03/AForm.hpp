#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
protected:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // getter 메소드
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    // 폼 서명
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;    //  추가된 함수

    // 예외 클래스
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    //  추가된 예외 클래스
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
