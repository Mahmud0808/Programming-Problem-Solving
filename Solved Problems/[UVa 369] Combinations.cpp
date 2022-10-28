#include <iostream>
#include <iomanip>
using namespace std;

#define ll long long unsigned int

int main()
{
	ll n, k;
	while (cin >> n >> k && (n || k))
	{
		if (k == 0 || k == n)
		{
			cout << fixed << setprecision(0) << n << " things taken " << k << " at a time is " << 1
				<< " exactly." << endl;
			continue;
		}
		else if (k == 1)
		{
			cout << fixed << setprecision(0) << n << " things taken " << k << " at a time is " << n
				<< " exactly." << endl;
			continue;
		}
		long double result = 1;
		for (int i = k + 1; i <= n; i++)
		{
			result *= (double)i / (double)(i - k);
		}
		cout << fixed << setprecision(0) << n << " things taken " << k << " at a time is " <<
			result << " exactly." << endl;
	}
}
