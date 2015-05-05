#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::sort;
using std::vector;
using std::domain_error

//Struct for Student info
struct Student_info
{
	string name;
	double midterm, final;
	vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
//Function to calculate Median
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size;
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	
	vec_sz mid = size / 2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid] - 1) / 2 : vec[mid];
}

//Grade taking 3 doubles
double grade(double midtern, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework
}

//Grade taking 2 doubles and a reference to const vector
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

//Grade for Student_info struct
double grade(const Student_info& s)
{
	return grade(s.midterm, sfinal, s.homework);
}

//Function to read input stream into vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		hw.clear();
		
		double x;
		while (in >> x)
			hw.push_back(x);
			
		in.clear();
	}
	return in;
}

//Read Stuff
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is, s.homework);
	return is;
}

//Main Function
int main()
{
	//Initialize vector of student info structs
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	//Read and store all recrods, find longest name
	while (read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	
	//Alphabetize records
	sort(students.begin(), students.end(), compare);
	
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		//Name padded to right based on longest name
		cout << students[i].name
			 << string(maxlen + 1 - students[i].name.size(), ' ');
		 
		try 
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3)  << final_grade
		 		 << setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	
	return 0;
}
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
	
	vector<double> homework;
	
	//Read HW Grades
	read_hw(cin, homework);
	
	//Compute Grade
	try
	{
		double final_grade = grade(midterm, final, homework);
		
		streamsize prec = cout.precision();
		cout << "Your final grade is : " << setprecision(3) 
		 	 << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error)
	{
		cout << endl << "You must enter your grades. "
						 "Please try again." << endl;
		return 1;
	}
	return 0;
}