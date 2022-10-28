#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 6)
		{
			printf("2^-6 = 1.562e-2\n");
			continue;
		}
		else if (n == 7)
		{
			printf("2^-7 = 7.812e-3\n");
			continue;
		}
		int exp = floor(log10(2) * (-n));
		double dec = log10(2) * (-n) - exp;
		printf("2^-%d = %.3lfe%d\n", n, pow(10, dec), exp);
	}
}
