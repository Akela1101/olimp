int pow(int x, llong a, int m)
{
	llong result = 1, y = x;
	for (; a; a >>= 1)
	{
		if (a & 1) result = result * y % m;
		
		y = y * y % m;
	}
	return (int)result;
}