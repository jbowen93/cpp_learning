map<string, vector<int> >
	xref(istream& in, 
		 vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;
	
	//Read next line
	while (getline(in, line))
	{
		++line_number;
		
		//Break input line into words
		vector<string> words = find_words(line);
		
		//Remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin();
			 it != words.end(); ++it)
			 ret[*it].push_back(line_number);
	}
	return ret;
}