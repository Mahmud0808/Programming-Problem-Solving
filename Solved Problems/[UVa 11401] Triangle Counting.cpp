#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	ll n, res;
	while (cin >> n && n >= 3)
	{
		res = 0;
		ll i = 1, N;
		while (2 * i + 1 < n)
		{
			N = n - (2 * i + 1);
			res += (N * (N + 1)) / 2;
			i++;
		}
		cout << res << endl;
	}
}
