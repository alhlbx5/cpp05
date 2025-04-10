#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void deleteForm(AForm*& formPtr) {
    delete formPtr;
    formPtr = NULL;
}

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- Testing Intern ---" << std::endl;
    Intern someRandomIntern;
    AForm* formPtr = NULL;

    std::cout << "\n[ Test 1: Valid 'robotomy request' ]" << std::endl;
    formPtr = someRandomIntern.makeForm("robotomy request", "Bender");
    if (formPtr) {
        std::cout << "Successfully created: " << *formPtr << std::endl;
        Bureaucrat signer("GoodSigner", 40);
        signer.signForm(*formPtr);
        signer.executeForm(*formPtr);
        deleteForm(formPtr);
    } else {
        std::cout << "Form creation failed." << std::endl;
    }


    std::cout << "\n[ Test 2: Valid 'shrubbery creation' ]" << std::endl;
    formPtr = someRandomIntern.makeForm("shrubbery creation", "home");
     if (formPtr) {
        std::cout << "Successfully created: " << *formPtr << std::endl;
        deleteForm(formPtr);
    } else {
        std::cout << "Form creation failed." << std::endl;
    }

    std::cout << "\n[ Test 3: Valid 'presidential pardon' ]" << std::endl;
    formPtr = someRandomIntern.makeForm("presidential pardon", "Marvin");
     if (formPtr) {
        std::cout << "Successfully created: " << *formPtr << std::endl;
        deleteForm(formPtr);
    } else {
        std::cout << "Form creation failed." << std::endl;
    }


    std::cout << "\n[ Test 4: Invalid 'invalid form type' ]" << std::endl;
    formPtr = someRandomIntern.makeForm("invalid form type", "target");
     if (formPtr) {
        std::cout << "ERROR: Shouldn't have created form!" << std::endl;
        deleteForm(formPtr);
    } else {
        std::cout << "Form creation correctly failed (returned NULL)." << std::endl;
    }

    std::cout << "\n[ Test 5: Case Sensitive Check 'Robotomy Request' ]" << std::endl;
    formPtr = someRandomIntern.makeForm("Robotomy Request", "CaseTest");
     if (formPtr) {
        std::cout << "ERROR: Shouldn't have created form (case sensitive)!" << std::endl;
        deleteForm(formPtr);
    } else {
        std::cout << "Form creation correctly failed (returned NULL due to case sensitivity)." << std::endl;
    }


    std::cout << "\n--- End of Intern Tests ---" << std::endl;
    return 0;
}
