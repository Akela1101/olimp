// number!
bool isPalind(int n)
{
	int r = 0, n0 = n;
	for( ; n; n /= 10 ) r = r * 10 + n % 10;
	return n0 == r;
}

// string!
bool isPalind(string s)
{
	int lenD2 = s.size() / 2;
	int lenS1 = s.size() - 1;
	for( int i = 0; i < lenD2; ++i ) if( s[i] != s[lenS1 - i] ) return false;
	return true;
}