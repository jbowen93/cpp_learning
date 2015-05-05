#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

//predicate for failing student
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

//Separate passing from failing (Third Try)
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	
	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}