#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

Intern::~Intern() {}

struct FormPair {
    const char* formName;
    AForm* (*createForm)(const std::string&);
};

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

FormPair formPairs[] = {
    {"shrubbery creation", createShrubberyCreationForm},
    {"robotomy request", createRobotomyRequestForm},
    {"presidential pardon", createPresidentialPardonForm}
};

const char* Intern::UnknownFormNameException::what() const throw() {
    return "Unknown form name";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (size_t i = 0; i < sizeof(formPairs) / sizeof(FormPair); ++i) {
        if (formName == formPairs[i].formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formPairs[i].createForm(target);
        }
    }
    throw UnknownFormNameException();
}
