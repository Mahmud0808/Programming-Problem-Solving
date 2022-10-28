#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int
#define maxN 100000000

vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	prime.push_back(2);
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	for (ll i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

vector < ll > res;

void check(ll n)
{
	ll sz = prime.size();
	for (ll i = 0; i < sz && prime[i] <= n; i++)
	{
		if (n % prime[i] == 0)
		{
			while (n % prime[i] == 0)
			{
				n /= prime[i];
				res.push_back(prime[i]);
			}
		}
	}
	if (n != 1)
		res.push_back(n);
}

int main()
{
	sieve();
	ll n;
	while (cin >> n && n >= 0)
	{
		if (n < 2)
			cout << "    " << n << endl << endl;
		else
		{
			check(n);
			int sz = res.size();
			for (int i = 0; i < sz; i++)
			{
				cout << "    " << res[i] << endl;
			}
			cout << endl;
			res.clear();
		}
	}
}
