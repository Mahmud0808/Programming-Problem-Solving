#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

#define maxN 10000005
#define ll long long int

int sz;
set < ll > divisor;
vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	prime.push_back(2);
	for (int i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	for (int i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

ll solve(ll N)
{
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		if (N % prime[i] == 0)
		{
			while (N % prime[i] == 0)
			{
				N /= prime[i];
			}
			divisor.insert(prime[i]);
		}
	}
	if (N != 1)
		divisor.insert(N);
	if (divisor.size() <= 1)
		return -1;
	else
		return *divisor.rbegin();
}

int main()
{
	sieve();
	sz = prime.size();
	ll N;
	while (cin >> N && N)
	{
		divisor.clear();
		cout << solve(abs(N)) << endl;
	}
}
