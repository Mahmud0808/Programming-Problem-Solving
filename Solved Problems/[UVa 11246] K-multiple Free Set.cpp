#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	int T, k;
	ll n, ans;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		ans = n;
		for (ll i = 1, j = k; n / j; i++, j *= k)
		{
			if (i & 1)
				ans -= n / j;
			else
				ans += n / j;
		}
		cout << ans << endl;
	}
}
