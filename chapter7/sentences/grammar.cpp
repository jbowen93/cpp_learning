typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");
	
	const int bucket_size = RAND_MAX / n;
	int r;
	
	do r = rand() / bucket_size;
	while (r >= n);
	
	return r;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if(!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		//Locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		
		//Fetch set of possible rules
		const Rule_collection& c = it->second;
		
		//Select one at random
		const Rule& r = c[nrand(c.size())];
		
		//Recursively expand selected rule
		for (Rule::const_iterator i = r.begin(); i!= r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

vector<string> gen_sentences(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line
	
	//Read input
	while (getline(in, line))
	{
		//Split input into words
		vector<string> entry = split(line);
		if (!entry.empty())
		{
			//Use category to store rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
			)
		}
	}
	return ret;
}

int main()
{
	//Generate sentences
	vector<string> sentences = gen_sentence(read_grammar(cin));
	
	//Write first word if any
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		++it;
	}
	//Write rest of words, each preceded by a space
	while (it =sentence.end())
	{
		cout << " " << *it;
		++it;
	}
	cout << endl;
	return 0;
}