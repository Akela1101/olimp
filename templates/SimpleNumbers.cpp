static const int N = 2000000;
static const int NQ2 = sqrt(N);
char isSimple[N];

fill_n(isSimple, N, 1);
isSimple[1] = 0; // bikkuri!
For( i, 2, N )
{
	if( isSimple[i] && i < NQ2 )
	{
		for( int j = i * i; j < N; j += i ) isSimple[j] = 0;
	}
}