template<udint... args> struct Arr_ { static const udint a[sizeof...(args)]; };
template<udint... args> const udint Arr_<args...>::a[sizeof...(args)] = { args... };

template<int N, template<udint> class F, udint... args>
struct Gen_ { typedef typename Gen_<N - 1, F, F<N>::f, args...>::type type; };

template<template<udint> class F, udint... args>
struct Gen_<0, F, args...> { typedef Arr_<F<0>::f, args...> type; };

template <udint i>
struct Fib_ { static const udint f = Fib_<i - 1>::f + Fib_<i - 2>::f; };
template <>
struct Fib_<0> { static const udint f = 1; };
template <>
struct Fib_<1> { static const udint f = 1; };

int main()
{
	const int count = 93;
	typedef Gen_<count, Fib_>::type Fib;

	for( int i = 89; i < count; ++i )
		std::cout << Fib::a[i] << std::endl;
}


// Runtime:
vector<udint> fib;
void GenFib()
{
	udint a = 0, b = 1, c;
	fib.reserve(93);
	fib.push_back(b);
	for( int i = 0; i < 92; ++i )
	{
		fib.push_back(c = b + a);
		a = b;
		b = c;
	}
}