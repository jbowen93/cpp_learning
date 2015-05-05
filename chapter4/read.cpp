#include "Student_info.h"

using std::istream;
using std::vector;

//Compare for Alphabetical Sorting
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	//Read student's name, midterm and final grade
	is >> s.name >> s.midterm >> s.final;
	
	//Read student's HW
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		//clear previous contents
		hw.clear();
		
		//read hw grades
		double x;
		while (in >> x)
			hw.push_back(x);
		
		//clear input stream
		in.clear();
	}
	return in;
}