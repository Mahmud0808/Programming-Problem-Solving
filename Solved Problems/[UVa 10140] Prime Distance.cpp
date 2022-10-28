#include <iostream>
#include <bitset>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long int

vector < ll > prime;
bitset < 100005 > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 100000; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
	}
}

bool check(ll N)
{
	ll sq = sqrt(N), sz = prime.size();
	for (int i = 0; i < sz && prime[i] <= sq; i++)
	{
		if (N % prime[i] == 0)
		{
			return false;
		}
	}
	return true;
}

ll nextPrime(ll N, ll U)
{
	if (N == 0)
		N++;
	for (ll num = N + 1; num <= U; num++)
	{
		if (check(num))
			return num;
	}
	return -1;
}

int main()
{
	sieve();
	ll L, U;
	while (cin >> L >> U)
	{
		int count = 0;
		ll num1, num2, MIN = INT_MAX, MAX = INT_MIN, C1, C2, D1, D2;
		num1 = nextPrime(L - 1, U);
		if (num1 != -1)
		{
			count++;
			while (true)
			{
				num2 = nextPrime(num1, U);
				if (num2 == -1)
					break;
				else
				{
					count++;
					if (num2 - num1 < MIN)
					{
						MIN = num2 - num1;
						C1 = num1, C2 = num2;
					}
					if (num2 - num1 > MAX)
					{
						MAX = num2 - num1;
						D1 = num1, D2 = num2;
					}
					num1 = num2;
				}
			}
		}
		if (count < 2)
			cout << "There are no adjacent primes." << endl;
		else
			cout << C1 << ',' << C2 << " are closest, " << D1 << ',' << D2 << " are most distant."
				<< endl;
	}
}
