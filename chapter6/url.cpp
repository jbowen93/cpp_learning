url_beg()

url_end()

vector<string> find_urls(const string&)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	
	//Look through input
	while (b != e)
	{
		//Look for letters followed by ://
		b = url_beg(b, e);
		
		//If found
		if (b != e)
		{
			//Get rest of url
			iter after = url_end(b, e);
			
			//remember the url
			ret.push_back(string(b, after));
			
			//advance b and check for more urls
			b = after;
		}
	}
	return ret; 
}