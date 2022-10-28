#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector < int >prime;
bitset < 10001 > isP;

void sieve()
{
	isP.set();
	for (int i = 2; i < 10001; i++)
	{
		if (isP[i])
		{
			prime.push_back(i);
			for (int j = i * i; j < 10001; j += i)
			{
				isP[j] = false;
			}
		}
	}
}

int solve(int n)
{
	int count = 0;
	int l = 0, r = prime.size() - 1;
	while (l <= r)
	{
		int sum = 0, i = l;
		while (i <= r)
		{
			sum += prime[i];
			if (sum == n)
			{
				count++;
				break;
			}
			if (sum > n)
				break;
			i++;
		}
		l++;
	}
	return count;
}

int main()
{
	sieve();
	int n;
	while (cin >> n && n)
	{
		cout << solve(n) << endl;
	}
}
