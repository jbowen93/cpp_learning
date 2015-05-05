#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

//Grade taking 3 doubles
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
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
	return grade(s.midterm, s.final, s.homework);
}