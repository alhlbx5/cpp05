#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string _codeName;
    int _clearanceLevel;  // 1 is highest, 150 is lowest

public:
    // Exception classes for clearance level validation
    class ClearanceTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class ClearanceTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    // Constructors and destructor
    Bureaucrat();
    Bureaucrat(const std::string& codeName, int clearanceLevel);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    
    // Assignment operator
    Bureaucrat& operator=(const Bureaucrat& other);
    
    // Getters
    std::string getCodeName() const;
    int getClearanceLevel() const;
    
    // Methods for changing clearance
    void promoteAgent();    // Increase clearance (decrease level number)
    void demoteAgent();     // Decrease clearance (increase level number)
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
