//predicate for failing student
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

//predicate for passing student
bool pgrade(const Student_info& s)
{
	return grade(s) >= 60;
}

//Two Passes
extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	
	remove_copy_if(students.begin(), students.end(), 
				   back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(),
				   fgrade), students.end());
    return fail;
}

//Single Pass 
extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter = 
		stable_partition(students.begin(), students.end(), pgrade);
	
	vector<Student_info> fail(iter, students.end());
	
	students.erase(iter,students.end());
	
	return fail;
}