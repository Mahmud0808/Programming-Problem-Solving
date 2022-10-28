#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long int

void primeGen(vector < int > &prime)
{
	bool primes[10005];
	memset(primes, true, sizeof(primes));
	for (int i = 2; i <= 10000; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				primes[j] = false;
			}
		}
	}
	for (int i = 3; i <= 10000; i++)
	{
		if (primes[i])
		{
			prime.push_back(i);
		}
	}
}

bool isPrime(ll N)
{
	int max = sqrt(N);
	bool prime = true;
	for (ll i = 2; i <= max; i++)
	{
		if (N % i == 0)
		{
			prime = false;
			break;
		}
	}
	if (prime)
		return true;
	else
		return false;
}

int main()
{
	vector < int > prime;
	primeGen(prime);
	ll n, a, b;
	bool brk;
	while (cin >> n && n)
	{
		brk = false;
		int size = prime.size();
		for (int i = n - 3; i >= 3; i--)
		{
			if (isPrime(i))
			{
				if (i + i == n)
				{
					a = i, b = i;
					brk = true;
				}
				else
				{
					for (int j = 0; j <= size; j++)
					{
						if (i + prime[j] == n)
						{
							a = prime[j];
							b = i;
							brk = true;
							break;
						}
						else if (i + prime[j] > n)
						{
							break;
						}
					}
				}
				if (brk)
					break;
			}
		}
		cout << n << " = " << a << " + " << b << endl;
	}
}
