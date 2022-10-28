// EULER'S PHI FUNCTION
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long int

vector < ll > prime;
bitset < 100005 > isPrime;

void sieve()
{
	isPrime.set();
	for (int i = 2; i * i < 100000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 100000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i < 100000; i++)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
}

int EulersPhi(ll N)
{
	ll res = N;
	int sz = prime.size();
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		if (N % prime[i] == 0)
		{
			while (N % prime[i] == 0)
			{
				N /= prime[i];
			}
			res *= (1.0 - (1.0 / prime[i]));
		}
	}
	if (N != 1)
		res *= (1.0 - (1.0 / N));
	return res;
}

int main()
{
	sieve();
	ll N;
	while (cin >> N && N)
	{
		if (N == 1)
		{
			cout << 0 << endl;
			continue;
		}
		else
			cout << EulersPhi(N) << endl;
	}
}
