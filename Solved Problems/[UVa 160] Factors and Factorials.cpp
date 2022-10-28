#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <map>
using namespace std;

vector < int >prime;

void sieve()
{
	bitset < 100 > bs;
	bs.set();
	for (int i = 2; i < 100; i++)
	{
		if (bs[i])
		{
			for (int j = i * i; j < 100; j += i)
			{
				bs[i] = false;
			}
			prime.push_back(i);
		}
	}
	return;
}

int main()
{
	sieve();
	int N;
	map < int, int >factor;
	while (cin >> N && N)
	{
		for (int i = N; i >= 2; i--)
		{
			int tmp = i;
			for (int j = 0; prime[j] <= tmp; j++)
			{
				if (tmp % prime[j] == 0)
				{
					while (tmp % prime[j] == 0)
					{
						tmp /= prime[j];
						factor[prime[j]]++;
					}
				}
			}
			if (tmp != 1)
			{
				factor[tmp]++;
			}
		}
		printf("%3d! =", N);
		int newl = 0;
		bool line = false;
		for (auto it = factor.begin(); it != factor.end(); it++)
		{
			newl++;
			if (line)
				printf("%9d", it->second);
			else
				printf("%3d", it->second);
			if (newl % 15 == 0)
			{
				cout << endl;
				line = true;
			}
			else
			{
				line = false;
			}
		}
		if (newl % 15 != 0)
			cout << endl;
		factor.clear();
	}
}
