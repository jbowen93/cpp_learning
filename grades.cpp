#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::sort;
using std::vector;

int main()
{
	//Greeting
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " + name + "!" << endl;
	
	//Get Test Grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	//Get Homework Grades
	cout << "Enter all your homework grades, followed by end-of-file: ";
	
	double x;
	vector<double> homework;
	
	while (cin >> x)
	{
		homework.push_back(x);
	}
	
	//Typedef
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	
	//Check for invalid input
	if (size == 0)
	{
		cout << endl << "You must enter your grades. "
						"Please try again." << endl;
		return 1;
	}
	
	//Sort
	sort(homework.begin(), homework.end());
	
	//Get Median
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
						   : homework[mid];
	
	//Get Final Grade and Output
	streamsize prec = cout.precision();
	cout << "Your final grade is : " << setprecision(3) 
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;
		 
	return 0;
}
