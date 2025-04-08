#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"
# include <cstdlib> 
# include <ctime>   

class RobotomyRequestForm : public AForm {

private:
    const std::string _target;
    RobotomyRequestForm(); 

protected:
    virtual void performAction() const;

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    const std::string& getTarget() const;
};

#endif
