#include <vector>
#include <string>
#include <iostream>
#include "width.h"
#include "frame.h"
#include "split.h"
#include "vcat.h"
#include "hcat.h"

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
		
		//Vcat
		vector<string> vert_cat = vcat(v, f);
		
		//Hcat
		vector<string> hor_cat = hcat(v, f);
		
		
		//write each line in vert_cat
//		for (vector<string>::size_type i = 0; i != vert_cat.size(); ++i)
//			cout << vert_cat[i] << endl;
			
		//write each line in hor_cat
		for (vector<string>::size_type i = 0; i != hor_cat.size(); ++i)
			cout << hor_cat[i] << endl;
	}
	return 0;
}