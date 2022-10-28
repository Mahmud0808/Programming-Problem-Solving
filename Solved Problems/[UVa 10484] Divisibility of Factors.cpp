#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#define ll long long int
#define maxN 46500

vector < ll > prime;
bitset < maxN > isP;
map < ll, ll > factor;

void sieve()
{
	isP.set();
	prime.push_back(2);
	for (int i = 4; i < maxN; i += 2)
		isP[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isP[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isP[j] = false;
	for (int i = 3; i < maxN; i += 2)
		if (isP[i])
			prime.push_back(i);
}

void factorCheck(ll N)
{
	ll tmp, count;
	for (int i = 0; prime[i] <= N; i++)
	{
		tmp = N, count = 0;
		while (tmp)
		{
			count += tmp / prime[i];
			tmp /= prime[i];
		}
		factor[prime[i]] = count;
	}
}

ll check(ll D)
{
	ll sz = prime.size(), count, ans = 1;
	for (int i = 0; i < sz && prime[i] <= D; i++)
	{
		count = 0;
		if (D % prime[i] == 0)
		{
			while (D % prime[i] == 0)
			{
				D /= prime[i];
				count++;
			}
			if (count <= factor[prime[i]])
				factor[prime[i]] -= count;
			else
				return 0;
		}
	}
	if (D != 1)
		factor[D]--;
  for (auto it:factor)
	{
		ans *= (it.second + 1);
	}
	return ans;
}

int main()
{
	sieve();
	ll N, D;
	while (cin >> N >> D && (N || D))
	{
		N = abs(N), D = abs(D);
		factorCheck(N);
		ll res = check(D);
		cout << res << endl;
		factor.clear();
	}
}
