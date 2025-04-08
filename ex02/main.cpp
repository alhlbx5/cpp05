#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <vector> 

int main() {
    std::srand(std::time(NULL));

    Bureaucrat highExec("Alice", 1);
    Bureaucrat midExec("Bob", 40);
    Bureaucrat lowExec("Charlie", 140);
    Bureaucrat signOnly("David", 145); 

    std::cout << highExec << std::endl;
    std::cout << midExec << std::endl;
    std::cout << lowExec << std::endl;
    std::cout << signOnly << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::vector<AForm*> forms;
    forms.push_back(new ShrubberyCreationForm("garden"));
    forms.push_back(new RobotomyRequestForm("Bender"));
    forms.push_back(new PresidentialPardonForm("Ford Prefect"));

    std::cout << "\n--- Testing Form Creation ---" << std::endl;
    for (size_t i = 0; i < forms.size(); ++i) {
        std::cout << *forms[i] << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;


    std::cout << "\n--- Testing Signing ---" << std::endl;
    lowExec.signForm(*forms[0]);  
    signOnly.signForm(*forms[0]); 

    lowExec.signForm(*forms[1]);  
    midExec.signForm(*forms[1]);  

    midExec.signForm(*forms[2]);  
    highExec.signForm(*forms[2]); 

    std::cout << "\n--- Form States After Signing Attempts ---" << std::endl;
    for (size_t i = 0; i < forms.size(); ++i) {
        std::cout << *forms[i] << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;


    std::cout << "\n--- Testing Execution ---" << std::endl;

    std::cout << "-- Shrubbery Execution --" << std::endl;
    highExec.executeForm(*forms[0]); 
    midExec.executeForm(*forms[0]);  
    lowExec.executeForm(*forms[0]);  
    ShrubberyCreationForm unsignedShrub("temp_garden");
    std::cout << unsignedShrub << std::endl;
    highExec.executeForm(unsignedShrub);

    std::cout << "\n-- Robotomy Execution --" << std::endl;
    highExec.executeForm(*forms[1]); 
    highExec.executeForm(*forms[1]); 
    midExec.executeForm(*forms[1]);  
    lowExec.executeForm(*forms[1]);  

    std::cout << "\n-- Pardon Execution --" << std::endl;
    highExec.executeForm(*forms[2]); 
    midExec.executeForm(*forms[2]);  

    std::cout << "-----------------------------------------" << std::endl;


    std::cout << "\n--- Cleaning up forms ---" << std::endl;
    for (size_t i = 0; i < forms.size(); ++i) {
        delete forms[i];
    }
    forms.clear(); 


    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
