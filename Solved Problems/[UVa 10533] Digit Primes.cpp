#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

vector < int >dprime;
bitset < 1000008 > isPrime;

bool digitPrime(int N)
{
	int sum = 0;
	while (N)
	{
		sum += (N % 10);
		N /= 10;
	}
	if (isPrime[sum])
		return true;
	else
		return false;
}

void sieve()
{
	isPrime.set();
	for (int i = 2; i * i < 1000000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 1000000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i < 1000000; i++)
	{
		if (isPrime[i] && digitPrime(i))
			dprime.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int N, t1, t2, upr, lwr;
	cin >> N;
	while (N--)
	{
		cin >> t1 >> t2;
		upr = upper_bound(dprime.begin(), dprime.end(), t2) - dprime.begin();
		lwr = lower_bound(dprime.begin(), dprime.end(), t1) - dprime.begin();
		cout << upr - lwr << endl;
	}
}
