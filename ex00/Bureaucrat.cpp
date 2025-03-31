#include "Bureaucrat.hpp"

// Exception implementation
const char* Bureaucrat::ClearanceTooHighException::what() const throw() {
    return "Security Breach: Attempted to assign clearance level above authorized limits";
}

const char* Bureaucrat::ClearanceTooLowException::what() const throw() {
    return "Protocol Violation: Attempted to assign clearance level below minimum threshold";
}

// Constructors and destructor implementation
Bureaucrat::Bureaucrat() : _codeName("Unnamed"), _clearanceLevel(150) {
    std::cout << "Agent initialized with default parameters" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& codeName, int clearanceLevel) : _codeName(codeName) {
    if (clearanceLevel < 1)
        throw ClearanceTooHighException();
    if (clearanceLevel > 150)
        throw ClearanceTooLowException();
    
    _clearanceLevel = clearanceLevel;
    std::cout << "Agent " << _codeName << " registered with clearance level " << _clearanceLevel << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _codeName(other._codeName), _clearanceLevel(other._clearanceLevel) {
    std::cout << "Agent " << _codeName << " cloned with clearance level " << _clearanceLevel << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Agent " << _codeName << " decommissioned" << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // Can't reassign _codeName since it's const
        _clearanceLevel = other._clearanceLevel;
        std::cout << "Agent " << _codeName << " clearance updated to " << _clearanceLevel << std::endl;
    }
    return *this;
}

// Getters implementation
std::string Bureaucrat::getCodeName() const {
    return _codeName;
}

int Bureaucrat::getClearanceLevel() const {
    return _clearanceLevel;
}

// Methods for changing clearance
void Bureaucrat::promoteAgent() {
    if (_clearanceLevel <= 1)
        throw ClearanceTooHighException();
    
    _clearanceLevel--;
    std::cout << "Agent " << _codeName << " promoted to clearance level " << _clearanceLevel << std::endl;
}

void Bureaucrat::demoteAgent() {
    if (_clearanceLevel >= 150)
        throw ClearanceTooLowException();
    
    _clearanceLevel++;
    std::cout << "Agent " << _codeName << " demoted to clearance level " << _clearanceLevel << std::endl;
}

// Stream insertion operator implementation
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Agent " << bureaucrat.getCodeName() << ", clearance level " << bureaucrat.getClearanceLevel();
    return os;
}
