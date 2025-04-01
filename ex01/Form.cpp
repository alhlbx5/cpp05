#include "Form.hpp"

static void	checkGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(_gradeToSign);
	checkGrade(_gradeToExecute);
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return (this->_name);
}
bool Form::isSigned() const
{
	return (this->_isSigned);
}
int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}
int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		throw Form::FormAlreadySignedException();
	}
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException: Grade requirement is too high (must be >= 1)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException: Grade requirement is too low (must be <= 150), or Bureaucrat grade insufficient");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("Form::FormAlreadySignedException: The form is already signed");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form '" << form.getName() << "', "
	   << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", "
	   << "Grade required to sign: " << form.getGradeToSign() << ", "
	   << "Grade required to execute: " << form.getGradeToExecute() << ";";
	return os;
}
