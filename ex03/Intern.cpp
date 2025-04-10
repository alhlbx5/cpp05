#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    typedef AForm* (*FormCreatorFunc)(const std::string&);

    struct FormType {
        std::string name;
        FormCreatorFunc creator;
    };

    FormType formTypes[] = {
        { "shrubbery creation", &Intern::createShrubberyForm },
        { "robotomy request", &Intern::createRobotomyForm },
        { "presidential pardon", &Intern::createPardonForm }
    };

    const int numFormTypes = sizeof(formTypes) / sizeof(formTypes[0]);
    AForm* createdForm = NULL;

    for (int i = 0; i < numFormTypes; ++i) {
        if (formName == formTypes[i].name) {
            createdForm = formTypes[i].creator(target);
            std::cout << "Intern creates " << createdForm->getName() << std::endl;
            return createdForm;
        }
    }

    std::cerr << "Intern cannot create form: Unknown form name '" << formName << "'" << std::endl;
    return NULL;
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Intern::UnknownFormException: The requested form name does not exist.";
}

