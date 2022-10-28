#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int
#define maxN 1000005

vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	prime.push_back(2);
	for (ll i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

ll ans;

void factorCheck(ll n)
{
	ll sz = prime.size(), count;
	ans = 1;
	for (int i = 0; i < sz && prime[i] <= n; i++)
	{
		count = 1;
		while (pow(prime[i], count) <= n)
		{
			count++;
		}
		ans *= pow(prime[i], count - 1);
		while (!(ans % 10))
		{
			ans /= 10;
		}
		ans %= 1000000000;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	ll n;
	while (cin >> n && n)
	{
		factorCheck(n);
		while (!(ans % 10))
		{
			ans /= 10;
		}
		cout << ans % 10 << endl;
	}
}
