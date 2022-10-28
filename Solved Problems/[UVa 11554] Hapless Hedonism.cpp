#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	int t;
	ll n, res;
	cin >> t;
	while (t--)
	{
		cin >> n;
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
