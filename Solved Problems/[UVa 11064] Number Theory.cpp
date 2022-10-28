#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define ll long long int
#define maxN 46500

vector < int >prime;
bitset < maxN > isPrime;

int sz;

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
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
	}
}

ll solve(int N)
{
	ll M = N, res = N, divisor = 1, count;
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		count = 1;
		if (N % prime[i] == 0)
		{
			while (N % prime[i] == 0)
			{
				N /= prime[i];
				count++;
			}
			divisor *= count;
			res *= (1.0 - (1.0 / prime[i]));
		}
	}
	if (N != 1)
	{
		divisor *= 2;
		res *= (1.0 - (1.0 / N));
	}
	return (M - res - divisor + 1);
}

int main()
{
	sieve();
	sz = prime.size();
	ll n;
	while (cin >> n)
	{
		cout << solve(n) << endl;
	}
}
