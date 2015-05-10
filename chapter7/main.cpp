#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "line_count.h"

int main()
{
	//Call xref
	map<string, vector<int> > ret = xref(cin);
	
	//Write Results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		 it != ret.end(); ++it)
	{
		//Write Word
		cout << it->first << " occurs on line(s): ";
		
		//Followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; //First line number
		
		++line_it;
		
		//Write rest of line numbers
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}
		
		//New line
		cout << endl;
	}
	
	return 0;
}