#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	ll N, M, res;
	while (cin >> N >> M)
	{
		res = 1;
		if (N == 0 && M != 0)
		{
			cout << 0 << endl;
			continue;
		}
		for (ll i = N; i >= N - M + 1; i--)
		{
			res *= i;
			while (!(res % 10))
			{
				res /= 10;
			}
			res %= 1000000000;
		}
		while (!(res % 10))
		{
			res /= 10;
		}
		cout << res % 10 << endl;
	}
}
