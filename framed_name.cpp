#include <iostream>
#include <string>

int main()
{
	//Get Name
	std::cout << "Please enter your first name: ";
	std::string name; //define variable name as a string
	std::cin >> name; //cin to get user input
	
	//Build greeting
	const std::string greeting = "Hello, " + name + "!";
	
	//Second and Fourth Lines
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";
	
	//First and Fifth Lines
	const std::string first(second.size(), '*');
	
	//Write Output
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	
	//Return
	return 0;	
}