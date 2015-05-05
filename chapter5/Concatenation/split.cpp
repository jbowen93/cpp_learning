#include <cctype>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	
	while (i != s.size())
	{
		//Ignore leading blanks
		while(i != s.size() && isspace(s[i]))
			++i;
		
		string_size j = i;
		//find end of next word
		while (j != s.size() && !isspace(s[j]))
			j++;
			
		//If we find non whitespace chars
		if (i != j)
		{
			//copy (j - i) chars from s starting at i 
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}