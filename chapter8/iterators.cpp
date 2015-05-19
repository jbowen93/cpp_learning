//Sequential Read Only (Input Iterator)
template <class In, class X> 
In find(In begin, In end, constX& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

//Sequential Write Only (Output Iterator)
template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

//Sequential Read-Write (Forward Iterator)
template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end)
	{
		if (*beg == x)
			*beg =y;
		++beg;
	}
}

//Reversible (Bidirectional Iterator)
template<class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

//Random Access
template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end)
	{
		//Find midpoint
		Ran mid = begin + (end - begin) / 2;
		//See which part of range contains x, keep looking only in that part
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		//if we got here, then *mid == x so we're done
		else return true;
	}
	return false;
}

//Invariant: must still process the elements in the range [begin, end)
while (begin != end)
{
	//do something with element to which begin refers
	++begin;
}
