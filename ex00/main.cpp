#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- BUREAU OF BUREAUCRATIC AFFAIRS ---" << std::endl;
    std::cout << "--- AGENT MANAGEMENT SYSTEM V1.0 ---" << std::endl;
    std::cout << std::endl;

    try {
        // Test constructors
        std::cout << "Creating agents..." << std::endl;
        Bureaucrat agent1;
        Bureaucrat agent2("Smith", 75);
        Bureaucrat agent3(agent2);
        
        std::cout << std::endl << "Displaying agent information:" << std::endl;
        std::cout << "Agent 1: " << agent1 << std::endl;
        std::cout << "Agent 2: " << agent2 << std::endl;
        std::cout << "Agent 3: " << agent3 << std::endl;

        // Test promotion and demotion
        std::cout << std::endl << "Testing agent promotions:" << std::endl;
        agent1.promoteAgent();
        agent2.promoteAgent();
        agent3.promoteAgent();
        
        std::cout << std::endl << "Updated agent status:" << std::endl;
        std::cout << "Agent 1: " << agent1 << std::endl;
        std::cout << "Agent 2: " << agent2 << std::endl;
        std::cout << "Agent 3: " << agent3 << std::endl;
        
        // Test assignment operator
        std::cout << std::endl << "Reassigning agent clearance:" << std::endl;
        agent3 = agent1;
        std::cout << "Agent 3 after reassignment: " << agent3 << std::endl;

    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    // Test boundary cases
    std::cout << std::endl << "--- TESTING BOUNDARY CASES ---" << std::endl;
    
    try {
        std::cout << "Creating agent with invalid high clearance:" << std::endl;
        Bureaucrat invalidAgent1("Invalid1", 0);
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    
    try {
        std::cout << std::endl << "Creating agent with invalid low clearance:" << std::endl;
        Bureaucrat invalidAgent2("Invalid2", 151);
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    
    try {
        std::cout << std::endl << "Testing promotion beyond maximum clearance:" << std::endl;
        Bureaucrat topAgent("Director", 1);
        std::cout << topAgent << std::endl;
        topAgent.promoteAgent();
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    
    try {
        std::cout << std::endl << "Testing demotion beyond minimum clearance:" << std::endl;
        Bureaucrat bottomAgent("Intern", 150);
        std::cout << bottomAgent << std::endl;
        bottomAgent.demoteAgent();
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << "--- END OF TESTS ---" << std::endl;
    
    return 0;
}
