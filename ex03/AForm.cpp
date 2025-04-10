#include "AForm.hpp"

void AForm::checkGrade(int grade) const {
    if (grade < 1) throw AForm::GradeTooHighException();
    if (grade > 150) throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return this->_name; }
bool AForm::isSigned() const { return this->_isSigned; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (this->_isSigned) {
         throw AForm::FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    this->performAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm::GradeTooHighException: Grade requirement is too high (< 1)";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm::GradeTooLowException: Grade requirement is too low (> 150) or Bureaucrat grade insufficient";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm::FormNotSignedException: The form must be signed before execution";
}
const char* AForm::FormAlreadySignedException::what() const throw() {
    return "AForm::FormAlreadySignedException: The form is already signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form '" << form.getName()
       << "', Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade Sign: " << form.getGradeToSign()
       << ", Grade Exec: " << form.getGradeToExecute();
    return os;
}
