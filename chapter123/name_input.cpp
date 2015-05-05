#include <iostream>
#include <string>

int main()
{
	//Get Name
	std::cout << "Please enter your first name: ";
	
	//Read in Name
	std::string name; //define variable name as a string
	std::cin >> name; //cin to get user input
	
	//Greeting
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;	
}