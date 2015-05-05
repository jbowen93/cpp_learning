#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	//Copy top picture
	vector<string> ret = top;
		
	//Copy bottom picture (Long way)
//	for (vector<string>::const_iterator iter = bottom.begin();
//		 iter != bottom.end(); ++iter)
//	{
//		ret.push_back(*iter);
//	}
//	
	//Copy bottom picture (Short way)
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	
	return ret;
}