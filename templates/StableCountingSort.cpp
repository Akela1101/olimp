template<typename _BI, typename _T>
void simple_csort(_BI iFrom, _BI iTill, _T first, _T nSigned)
{
	if( !nSigned ) return;
	_T n = abs(nSigned);

	vector<int> vCount(n);
	for( _BI i = iFrom; i != iTill; ++i ) ++vCount[*i - first];

	_BI i = iTill;
	if( nSigned > 0 ) // ascending
	{
		for( _T j = n - 1; j >= 0; --j ) while( vCount[j]-- ) *--i = j + first;
	}
	else // descending
	{
		for( _T j = 0; j < n; ++j ) while( vCount[j]-- ) *--i = j + first;
	}
}

template<typename _BI, typename _RI, typename _T>
void csort_copy(_BI iFrom, _BI iTill, _RI iOut, _T first, _T nSigned)
{
	if( !nSigned ) return;
	_T n = abs(nSigned);

    function<int(_T)> Index;
    if( nSigned > 0 ) // ascending
    {
        Index = [first](_T x) { return x - first; };
    }
    else // descending
    {
        _T last = n - 1 + first;
        Index = [last](_T x) { return last - x; };
    }

	vector<int> vCount(n);
	for( _BI i = iFrom; i != iTill; ++i ) ++vCount[Index(*i)];

	for( int j = 0, sum = 0; j < n; ++j ) if( vCount[j] ) vCount[j] += sum, sum = vCount[j];

	for( _BI i = iTill; i != iFrom; ) iOut[--vCount[Index(*--i)]] = *i;
}

template<typename _BI, typename _T>
void csort(_BI iFrom, _BI iTill, _T first, _T nSigned)
{
	vector<_T> out(iTill - iFrom);

	csort_copy(iFrom, iTill, out.begin(), first, nSigned);
	copy(out.begin(), out.end(), iFrom);
}