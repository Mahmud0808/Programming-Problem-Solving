#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

unsigned long long seed;
long double x[10000005];

long double gen()
{
	static const long double Z = ( long double )1.0 / (1LL<<32);
	seed >>= 16;
	seed &= ( 1ULL << 32 ) - 1;
	seed *= seed;
	return seed * Z;
}

int main()
{
	int N, cs=1;
	long long int n;
	long double m, deviation, tmp;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%lld %llu", &n, &seed);
		m = 0, deviation = 0;
		for (int i=1; i<=n; i++)
		{
			x[i] = gen();
			m += x[i];
		}
		m /= n;
		for (int i=1; i<=n; i++)
		{
			deviation += (x[i]-m) * (x[i]-m);
		}
		deviation /= n;
		printf("Case #%d: %.5Lf\n", cs++, sqrt(deviation));;
	}
}
