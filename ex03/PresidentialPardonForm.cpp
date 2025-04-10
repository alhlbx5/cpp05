#include "PresidentialPardonForm.hpp"

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon Form", PPF_SIGN_GRADE, PPF_EXEC_GRADE),
    _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other),
    _target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::performAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
