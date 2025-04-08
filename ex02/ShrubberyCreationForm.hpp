#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
    const std::string _target;
    ShrubberyCreationForm();

protected:
    virtual void performAction() const;

public:
    ShrubberyCreationForm(const std::string& target);
     ShrubberyCreationForm(const ShrubberyCreationForm& other);
     ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    virtual ~ShrubberyCreationForm();

    const std::string& getTarget() const;
};

#endif 
