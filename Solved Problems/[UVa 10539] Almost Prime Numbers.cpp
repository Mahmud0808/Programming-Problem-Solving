#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int
#define maxN 1000005

vector < ll > prime;
bitset < maxN > isPrime;

bool check(ll N)
{
	int sz = prime.size(), count = 0, mx = N / 2;
	for (ll i = 0; i < sz && prime[i] <= mx; i++)
	{
		if (N % prime[i] == 0)
			count++;
		if (count > 1)
			return false;
	}
	if (count)
		return true;
	else
		return false;
}

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	for (ll i = 2; i < maxN; i++)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
}

ll aprime(ll low, ll high)
{
	ll count = 0, sz = prime.size();
	for (ll i = 0; i < sz; i++)
	{
		if (prime[i] * prime[i] > high)
			break;
		for (ll j = prime[i] * prime[i]; j <= high; j *= prime[i])
		{
			if (j >= low)
				count++;
		}
	}
	return count;
}

int main()
{
	sieve();
	ll N, low, high;
	cin >> N;
	while (N--)
	{
		cin >> low >> high;
		cout << aprime(low, high) << endl;
	}
}
