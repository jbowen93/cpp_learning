#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	string s;
	map<string, int>counters; //Store each word as associated counter
	
	//Read input
	while (cin >> s)
		++counters[s];
		
	//Write words and associated counts
	for (map<string, int>::const_iterator it = counters.begin();
		 it != counters.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	return 0;
}