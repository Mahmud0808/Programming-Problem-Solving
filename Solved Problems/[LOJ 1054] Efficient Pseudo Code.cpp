#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#define ll long long int
#define mod 1000000007

bitset < 65536 > isPrime;
vector < int >prime;
int sz;

void sieve()
{
	isPrime.set();
	prime.push_back(2);
	for (int i = 4; i < 65536; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < 65536; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < 65536; j += 2 * i)
				isPrime[j] = false;
	for (int i = 3; i < 65536; i += 2)
		if (isPrime[i])
			prime.push_back(i);
	sz = prime.size();
}

ll bigpow(ll n, ll k)
{
	if (k == 0)
		return 1;
	if (k & 1)
	{
		ll res = ((n % mod) * (bigpow(n, k - 1) % mod)) % mod;
		return res;
	}
	else
	{
		ll res = ((bigpow(n, k / 2) % mod) * (bigpow(n, k / 2) % mod)) % mod;
		return res;
	}
}

ll modinverse(ll n)
{
	return bigpow(n, mod - 2);
}

ll solve(ll n, ll m)
{
	map < ll, ll > power;
	ll res = 1;
	for (int i = 0; prime[i] * prime[i] <= n && i < sz; i++)
	{
		if (n % prime[i] == 0)
		{
			while (n % prime[i] == 0)
			{
				n /= prime[i];
				power[prime[i]]++;
			}
			power[prime[i]] *= m;
			power[prime[i]]++;
			ll numerator = (bigpow(prime[i], power[prime[i]]) - 1) % mod;
			ll denominator = modinverse(prime[i] - 1) % mod;
			res *= (((numerator % mod) * (denominator % mod)) % mod);
			res %= mod;
		}
	}
	if (n != 1)
	{
		power[n] = m + 1;
		ll numerator = (bigpow(n, power[n]) - 1) % mod;
		ll denominator = modinverse(n - 1) % mod;
		res *= (((numerator % mod) * (denominator % mod)) % mod);
		res %= mod;
	}
	return res;
}

int main()
{
	sieve();
	int T, cs = 1;
	ll n, m;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		ll res = solve(n, m);
		if (res <= 0)
			res = 1;
		cout << "Case " << cs++ << ": " << res << endl;
	}
}
