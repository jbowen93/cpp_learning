//Source file for median function
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	
	vec_sz mid = size / 2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid] - 1) / 2 : vec[mid];
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.(end), back_inserter(nonzero), 0);
	
	if (nonzero.empy())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}