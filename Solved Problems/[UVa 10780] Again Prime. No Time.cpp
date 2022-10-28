#include <iostream>
#include <bitset>
#include <vector>
#include <map>
#include <climits>
using namespace std;

#define maxN 10005

vector < int >prime;
bitset < maxN > isP;
map < int, int >factor;

void sieve()
{
	isP.set();
	for (int i = 2; i < maxN; i++)
	{
		if (isP[i])
		{
			for (int j = i * i; j < maxN; j += i)
			{
				isP[j] = false;
			}
			prime.push_back(i);
		}
	}
}

void factorCheck(int m)
{
	int count, res = INT_MAX;
	for (int i = 0; prime[i] <= m; i++)
	{
		count = 0;
		if (m % prime[i] == 0)
		{
			while (m % prime[i] == 0)
			{
				m /= prime[i];
				count++;
			}
			factor[prime[i]] = count;
		}
	}
	if (m != 1)
	{
		factor[m]++;
	}
}

int solve(int n)
{
	int count, tmp, res = INT_MAX;
  for (auto it:factor)
	{
		tmp = n, count = 0;
		while (tmp)
		{
			count += tmp / it.first;
			tmp /= it.first;
		}
		if (count < it.second)
			return -1;
		res = min(res, count / it.second);
	}
	return res;
}

int main()
{
	sieve();
	int t, m, n, cs = 1;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		factorCheck(m);
		int ans = solve(n);
		if (ans >= 0)
			cout << "Case " << cs++ << ':' << endl << ans << endl;
		else
			cout << "Case " << cs++ << ':' << endl << "Impossible to divide" << endl;
		factor.clear();
	}
}
