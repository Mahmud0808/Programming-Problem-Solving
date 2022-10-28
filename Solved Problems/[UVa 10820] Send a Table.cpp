#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define maxN 250

vector < int >prime;
bitset < maxN > isPrime;
long int ans[50005];

void sieve()
{
	isPrime.set();
	for (int i = 2; i < maxN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < maxN; j += i)
			{
				isPrime[j] = false;
			}
			prime.push_back(i);
		}
	}
}

long int EulersPhi(int n)
{
	int sz = prime.size(), count = n;
	for (int i = 0; i < sz && prime[i] <= n; i++)
	{
		if (n % prime[i] == 0)
		{
			while (n % prime[i] == 0)
			{
				n /= prime[i];
			}
			count *= (1.0 - (1.0 / prime[i]));
		}
	}
	if (n != 1)
		count *= (1.0 - (1.0 / n));
	return count;
}

void preCalc()
{
	ans[1] = 1;
	for (int i = 2; i <= 50000; i++)
	{
		ans[i] = ans[i - 1] + EulersPhi(i) * 2;
	}
}

int main()
{
	sieve();
	preCalc();
	int N;
	while (cin >> N && N)
	{
		cout << ans[N] << endl;
	}
}
