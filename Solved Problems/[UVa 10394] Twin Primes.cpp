#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define ll long long int

vector < ll > prime;
bitset < 20000005 > isPrime;

struct link
{
	ll x, y;
} p;

vector < link > tprime;

void sieve()
{
	isPrime.set();
	for (ll i = 4; i <= 20000000; i += 2)
	{
		isPrime[i] = false;
	}
	for (ll i = 3; i * i <= 20000000; i += 2)
	{
		if (isPrime[i])
		{
			for (ll j = i * i; j <= 20000000; j += i + i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (ll i = 3; i <= 20000000; i += 2)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
	int sz = prime.size();
	for (ll i = 0; i < sz - 1; i++)
	{
		if (prime[i + 1] - prime[i] == 2)
		{
			p.x = prime[i];
			p.y = prime[i + 1];
			tprime.push_back(p);
		}
	}
}

int main()
{
	sieve();
	ll S;
	while (cin >> S)
	{
		cout << '(' << tprime[S - 1].x << ", " << tprime[S - 1].y << ')' << endl;
	}
}
