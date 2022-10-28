#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int
#define maxN 5761460

vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	prime.push_back(2);
	for (ll i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
}

ll check(ll N)
{
	ll sz = prime.size(), ans = N;
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		if (N % prime[i] == 0)
		{
			while (N % prime[i] == 0)
			{
				N /= prime[i];
			}
			ans *= (1.0 - (1.0 / prime[i]));
		}
	}
	if (N != 1)
		ans *= (1.0 - (1.0 / N));
	return ans;
}

int main()
{
	sieve();
	ll N;
	while (cin >> N && N)
	{
		cout << check(N) << endl;
	}
}
