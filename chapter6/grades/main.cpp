bool did_all_hw(const Student_info& s)
{
	return((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

int main()
{
	//Students who did and didn't do homework
	vector<Student_info> did, didnt;
	Student_info student;
	
	//Read all records, separate based on whether all homework was done
	while (read(cin, student))
	{
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}
	
	//Check that both groups contain data
	if (did.empty())
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	
	if (didnt.empty())
	{
		cout << "Every student did all the homework" << endl;
		return 1;
	}
	
	//Do the analysis
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
				   optimistic_median_analysis, did, didnt);
    return 0;
}