#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int
#define maxN 3000000

vector < ll > prime;
bitset < maxN > isPrime;
ll ans[maxN];

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < maxN; i++)
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

void preCalc()
{
	ll sz = prime.size(), tmp, count, j;
	ans[0] = ans[1] = 0;
	for (int i = 2; i < maxN; i++)
	{
		tmp = i, count = 0, j = 0;
		while (!isPrime[tmp] && j < sz)
		{
			if (tmp % prime[j] == 0)
			{
				while (tmp % prime[j] == 0)
				{
					tmp /= prime[j];
					count++;
				}
			}
			j++;
		}
		if (tmp != 1)
			count++;
		ans[i] = ans[i - 1] + count;
	}
}

ll bs(ll N, ll low, ll high)
{
	if (N == 0)
		return 0;
	if (low <= high)
	{
		ll mid = (low + high) / 2;
		if (ans[mid] == N)
			return mid;
		if (ans[mid] < N)
			return bs(N, mid + 1, high);
		else
			return bs(N, low, mid - 1);
	}
	return -1;
}

int main()
{
	sieve();
	preCalc();
	ll N, cs = 1, res;
	while (cin >> N && N >= 0)
	{
		res = bs(N, 0, maxN);
		if (res >= 0)
			cout << "Case " << cs++ << ": " << res << '!' << endl;
		else
			cout << "Case " << cs++ << ": Not possible." << endl;
	}
}
