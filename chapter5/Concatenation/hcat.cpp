#include <vector>
#include <string>
#include "width.h"

using std::vector;
using std::string;

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	
	//Leave space between pictures
	string::size_type width1 = width(left) + 1;
	
	//Indices
	vector<string>::size_type i = 0, j = 0;
	
	//Get all rows from both pictures
	while (i != left.size() || j != right.size())
	{
		string s;
		
		//Copy row from left (if possible)
		if (i != left.size())
			s = left[i++];
			
		//Pad to full width
		s += string(width1 - s.size(), ' ');
		
		//copy row from right (if possible)
		if (j != right.size())
			s += right[j++];
			
		//Add s to picture
		ret.push_back(s);
	}
	return ret;
}