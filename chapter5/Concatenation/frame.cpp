#include <vector>
#include <string>
#include <iostream>
#include "width.h"

using std::string;
using std::vector;

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');
	
	//Write top border
	ret.push_back(border);
	
	//Write interior row
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	{
		ret.push_back( "* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
	
	//Write bottom border
	ret.push_back(border);
	return ret;
}