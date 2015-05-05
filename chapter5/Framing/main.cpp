#include <vector>
#include <string>
#include <iostream>
#include "width.h"
#include "frame.h"
#include "split.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	string s;	
	//read and split each line of input
	while (getline(cin, s))
	{
		//Get words
		vector<string> v = split(s);
		
		//Frame
		vector<string> f = frame(v);
		
		//write each word in f
		for (vector<string>::size_type i = 0; i != f.size(); ++i)
			cout << f[i] << endl;
	}
	return 0;
}