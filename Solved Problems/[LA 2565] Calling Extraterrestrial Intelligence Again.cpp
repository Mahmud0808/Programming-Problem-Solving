#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

vector < int >prime;
bitset < 50005 > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < 50005; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < 50005; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < 50005; j += 2 * i)
				isPrime[j] = false;
	prime.push_back(2);
	for (int i = 3; i < 50005; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

int main()
{
	sieve();
	int m, a, b, p, q, sz = prime.size();
	while (cin >> m >> a >> b && (m && a && b))
	{
		int sq = sqrt(m) + 1;
		p = 2, q = 2;
		double fraction;
		for (int i = 0; i < sz && prime[i] <= sq; i++)
		{
			for (int j = 0; j < sz && prime[i] * prime[j] <= m; j++)
			{
				fraction = (double)prime[i] / prime[j];
				if (prime[i] * prime[j] > p * q && fraction >= (double)a / b && fraction <= 1.0)
				{
					p = prime[i];
					q = prime[j];
				}
			}
		}
		cout << min(p, q) << ' ' << max(p, q) << endl;
	}
}
