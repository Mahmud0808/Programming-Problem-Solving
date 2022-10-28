#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long int

vector < ll > prime;
bitset < 100000005 > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 4; i <= 100000000; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i <= 100000000; i += 2)
	{
		if (isPrime[i])
		{
			for (ll j = i * i; j <= 100000000; j += 2 * i)
			{
				isPrime[j] = false;
			}
		}
	}
	ll sz = (100000000 / 2) + 10000;
	prime.push_back(2);
	for (ll i = 3; i <= sz; i += 2)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
}

int main()
{
	sieve();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, sz = prime.size(), p1, p2;
	while (cin >> n)
	{
		bool res = false;
		if (n == 0 || n == 1)
		{
			res = false;
		}
		else if (n % 2 == 1)
		{
			if (isPrime[n - 2])
			{
				res = true;
				p1 = 2;
				p2 = n - 2;
			}
		}
		else
		{
			ll lwr = lower_bound(prime.begin(), prime.end(), n / 2) - prime.begin();
			for (ll i = lwr; i >= 0; i--)
			{
				if (isPrime[n - prime[i]] && prime[i] != n - prime[i])
				{
					res = true;
					p1 = min(prime[i], n - prime[i]);
					p2 = max(prime[i], n - prime[i]);
					break;
				}
			}
		}
		if (res)
			cout << n << " is the sum of " << p1 << " and " << p2 << '.' << endl;
		else
			cout << n << " is not the sum of two primes!" << endl;
	}
}
