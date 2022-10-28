#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector < int >prime;
bitset < 10000 > isPrime;

void sieve()
{
	isPrime.set();
	for (int i = 2; i < 10000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 10000; j += i)
			{
				isPrime[j] = false;
			}
			prime.push_back(i);
		}
	}
}

int main()
{
	sieve();
	int M, N;
	cin >> M;
	while (M--)
	{
		cin >> N;
		int idx = lower_bound(prime.begin(), prime.end(), N / 2) - prime.begin() - 1;
		while (prime[idx] * 2 <= N)
		{
			idx++;
		}
		cout << prime[idx] << endl;
	}
}
