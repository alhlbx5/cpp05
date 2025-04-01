#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	testBureaucratBasics(void)
{
	std::cout << "\n--- Testing Bureaucrat Basics ---" << std::endl;
	try
	{
		Bureaucrat b1("Buro1", 1);
		std::cout << b1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("Buro2", 150);
		std::cout << b2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b3("Buro3", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("Buro4", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
}

void	testFormBasics(void)
{
	std::cout << "\n--- Testing Form Basics ---" << std::endl;
	try
	{
		Form f1("F1", 1, 1);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form f2("F2", 150, 150);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form f3("F3", 0, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form f4("F4", 10, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
}

void	testSigning(void)
{
	std::cout << "\n--- Testing Form Signing ---" << std::endl;
	Bureaucrat highGrade("Alice", 10);
	Bureaucrat midGrade("Bob", 75);
	Bureaucrat lowGrade("Charlie", 140);
	std::cout << highGrade << "\n" << midGrade << "\n" << lowGrade << std::endl;
	Form easyForm("Easy Permit", 100, 100);
	Form hardForm("Top Secret Clearance", 15, 5);
	std::cout << easyForm << "\n" << hardForm << std::endl;
	std::cout << "\n-- Attempting to sign Easy Permit --" << std::endl;
	lowGrade.signForm(easyForm);
	midGrade.signForm(easyForm);
	highGrade.signForm(easyForm);
	std::cout << "\n-- Attempting to sign Top Secret Clearance --" << std::endl;
	lowGrade.signForm(hardForm);
	midGrade.signForm(hardForm);
	highGrade.signForm(hardForm);
	highGrade.signForm(hardForm);
	std::cout << "\n-- Final Form States --" << std::endl;
	std::cout << easyForm << std::endl;
	std::cout << hardForm << std::endl;
	std::cout << "\n-- Direct beSigned calls --" << std::endl;
	try
	{
		Form testForm("Direct Test", 50, 50);
		Bureaucrat signer("Direct Signer", 60);
		std::cout << testForm << std::endl;
		std::cout << signer << std::endl;
		testForm.beSigned(signer);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	try
	{
		Form testForm2("Direct Test 2", 50, 50);
		Bureaucrat signer2("Direct Signer 2", 40);
		std::cout << testForm2 << std::endl;
		std::cout << signer2 << std::endl;
		testForm2.beSigned(signer2);
		std::cout << "Sign successful." << std::endl;
		std::cout << testForm2 << std::endl;
		testForm2.beSigned(signer2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	testBureaucratBasics();
	testFormBasics();
	testSigning();
	std::cout << "\n--- End of Tests ---" << std::endl;
	return (0);
}
