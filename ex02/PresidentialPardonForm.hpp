#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
    const std::string _target;
    PresidentialPardonForm(); 

protected:
    virtual void performAction() const;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

    const std::string& getTarget() const;
};

#endif 
