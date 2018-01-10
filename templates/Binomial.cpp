typedef int valueType;
template<typename T>
constexpr int maxN()
{
	return is_same<int, T>() ? 34
		: is_same<uint, T>() ? 35
		: is_same<llong, T>() ? 67
		: is_same<ullong, T>() ? 68
		: 0;
}

vector<vector<valueType>> bC;

void Binomial(int n = maxN<valueType>())
{
	bC.resize(n);
	bC[0].resize(2);
	bC[0][0] = 1;
	for( int i = 1; i < n; ++i )
	{
		bC[i].resize(i + 2);
		bC[i][0] = 1;
		for( int j = 1; j <= i; ++j )
		{
			bC[i][j] = (bC[i-1][j] + bC[i-1][j-1]);
		}
	}
}