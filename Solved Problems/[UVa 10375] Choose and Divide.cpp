#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double C(long long int n, long long int k)
{
	long double res = 1;
	for (long long int i = k + 1; i <= n; i++)
	{
		res *= (double)i / (i - k);
	}
	return res;
}

int main()
{
	long long int p, q, r, s;
	long double res;
	while (cin >> p >> q >> r >> s)
	{
		res = C(p, q) / C(r, s);
		cout << fixed << setprecision(5) << res << endl;
	}
}
