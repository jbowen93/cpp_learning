bool not_url_char(char c)
{
	//Possible chars in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	
	//Check whether c can appear in a URL
	return !(isalnum(c) || 
			 find(url_ch.begin()m url_ch.end(), c) != url_ch.end());
}

url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	
	typedef string::const_iterator iter;
	
	//i marks where seperator was found
	iter i = b;
	
	while ((i = search(i, e, sep.begin(), sep.end())) != e
	{
		if (i != b && i + setp.size() != e)
		{
			//beg marks beginning of protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;
				
			//Is ther at least one appropriate char before and after
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		
		//Separator we found wasn't part of URL so advance i past it
		i += sep.size();
	}
	return e;
}

url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

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