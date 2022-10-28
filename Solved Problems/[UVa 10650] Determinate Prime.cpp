#include <iostream>
#include <vector>
#include <bitset>
#include <set>
using namespace std;

vector < int >prime;
bitset < 32005 > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 32000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 32000; j += i)
			{
				isPrime[j] = false;
			}
			prime.push_back(i);
		}
	}
}

set < int >series;
vector < vector < int >>dprime;

void twin()
{
	int sz = prime.size();
	for (int i = 0; i < sz - 2; i++)
	{
		if (prime[i + 2] - prime[i + 1] == prime[i + 1] - prime[i])
		{
			series.insert(prime[i]);
			series.insert(prime[i + 1]);
			series.insert(prime[i + 2]);
		}
		else
		{
			if (series.size() >= 3)
			{
				vector < int >tmp(series.begin(), series.end());
				dprime.push_back(tmp);
				tmp.clear();
			}
			series.clear();
		}
	}
}

int main()
{
	sieve();
	twin();
	int x, y;
	set < int >::iterator it;
	while (cin >> x >> y && (x || y))
	{
		int sz = dprime.size();
		if (x > y)
			swap(x, y);
		for (int i = 0; i < sz; i++)
		{
			bool print = false;
			int count = 0;
			if (dprime[i][0] > y)
				break;
			for (int j = 0; j < dprime[i].size(); j++)
			{
				if (dprime[i][j] >= x && dprime[i][j] <= y)
					count++;
			}
			if (count == dprime[i].size())
				print = true;
			if (print)
			{
				for (int j = 0; j < dprime[i].size(); j++)
				{
					if (j != 0)
						cout << ' ';
					cout << dprime[i][j];
				}
				cout << endl;
			}
		}
	}
}
