#include "RobotomyRequestForm.hpp"

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE),
    _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other),
    _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::performAction() const {
    std::cout << "* VRRRRRRR... BZZZZZZ... DRILLLLLLLL *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
    }
}
