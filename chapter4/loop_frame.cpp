#include <iostream>
#include <string>

//Namespace Stuff
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
	//Get Name
	std::cout << "Please enter your first name: ";
	
	//Read in Name
	string name;
	cin >> name; 
	
	//Greeting
	const string greeting =  "Hello, " + name + "!";
	
	//Padding
	const int pad = 1;
	
	//Rows and Columns
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	
	//Blank Line
	cout << endl;
	
	//Rows of output
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		
		while (c != cols)
		{
			if (r == pad + 1 && c == pad +1)
			{
				//Greeting
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				//Border
				if (r == 0 || r == rows - 1 || c == 0 || c == cols -1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		
		cout << endl;
	}
	
	return 0;	
}