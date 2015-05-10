double grade_aux(const Student_info& s)
{
	try
	{
		return grade(s);	
	}
	catch (domain_error)
	{
		return grade(s.midterm, s.final, 0);
	}
	
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	
	return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	
	return median(grades);
}

void optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	
	return median(grades);
	
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
					const vector<Student_info>& did), const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << 
				   ", median(didnt) = " << analysis(didnt) << endl;
}