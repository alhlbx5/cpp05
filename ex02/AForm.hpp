#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm {

private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

protected:
    virtual void performAction() const = 0;
    void checkGrade(int grade) const;


public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
     class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
     class FormAlreadySignedException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
