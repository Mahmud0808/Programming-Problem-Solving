#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

#define ll long long int
#define maxN 46350

vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	for (int i = 2; i * i < maxN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < maxN; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	prime.push_back(2);
	for (int i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

int calc(ll n)
{
	if (n == 1)
		return 2;
	ll m = n, sz = prime.size(), ans = 0, count;
	for (ll i = 0; i < sz && prime[i] <= n; i++)
	{
		count = 0;
		if (n % prime[i] == 0)
		{
			while (n % prime[i] == 0)
			{
				n /= prime[i];
				count++;
			}
			ans += pow(prime[i], count);
		}
	}
	if (n != 1)
	{
		ans += n;
	}
	if (ans == m)
		return m + 1;
	return ans;
}

int main()
{
	sieve();
	ll n, cs = 1;
	while (cin >> n && n)
	{
		if (n == 2147483647)
		{
			cout << "Case " << cs++ << ": " << 2147483648 << endl;
			continue;
		}
		cout << "Case " << cs++ << ": " << calc(n) << endl;
	}
}
