#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <climits>
#include <cstdio>
using namespace std;

#define ll long long int
#define maxN 1048580

double num[maxN];
vector < ll > prime;
bitset < maxN > isP;

void sieve()
{
	isP.set();
	for (int i = 4; i < maxN; i += 2)
		isP[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isP[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isP[j] = false;
	prime.push_back(2);
	for (int i = 3; i < maxN; i += 2)
		if (isP[i])
			prime.push_back(i);
}

void logarithm()
{
	num[0] = num[1] = 0.0;
	for (int i = 2; i < maxN; i++)
	{
		num[i] = num[i - 1] + log(i);
	}
}

ll trailZero(ll N, ll B)
{
	sieve();
	ll count = INT_MAX, count1, count2, tmp, sz = prime.size();
	for (int i = 0; i < sz && prime[i] <= B; i++)
	{
		if (B % prime[i] == 0)
		{
			count1 = 0, count2 = 0, tmp = N;
			while (B % prime[i] == 0)
			{
				B /= prime[i];
				count1++;
			}
			while (tmp)
			{
				count2 += tmp / prime[i];
				tmp /= prime[i];
			}
			count = min(count, count2 / count1);
		}
	}
	return count;
}

int main()
{
	sieve();
	logarithm();
	ll N, B;
	while (cin >> N >> B)
	{
		ll zero = trailZero(N, B), digit = floor((num[N] / log(B)) + 1);
		printf("%lld %lld\n", zero, digit);
	}
}
