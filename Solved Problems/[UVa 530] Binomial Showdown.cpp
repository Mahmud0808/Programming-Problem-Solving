#include <iostream>
#include <iomanip>
using namespace std;

#define ll long long int

int main()
{
	ll n, k;
	while (cin >> n >> k && (n || k))
	{
		if (k == 0 || k == n)
		{
			cout << 1 << endl;
			continue;
		}
		else if (k == 1)
		{
			cout << n << endl;
			continue;
		}
		long double result = 1;
		for (int i = k+1; i <= n; i++)
		{
			result *= (double)i/(double)(i-k);
		}
		cout << fixed << setprecision(0) << result << endl;
	}
}
