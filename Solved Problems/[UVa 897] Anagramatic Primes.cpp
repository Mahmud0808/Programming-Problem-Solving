#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxN 100000005

vector < int >prime;
bitset < maxN > isP;

void sieve()
{
	isP.set();
	isP[0] = false;
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

bool check(int n)
{
	string str = to_string(n);
	int sz = str.size() - 1, temp;
	sort(str.begin(), str.end());
	temp = 0;
	for (int i = sz; i >= 0; i--)
	{
		int x = str[i] - 48;
		if (!x)
			return false;
		temp = temp * 10 + x;
	}
	if (!isP[temp])
		return false;
	while (next_permutation(str.begin(), str.end()))
	{
		temp = 0;
		for (int i = sz; i >= 0; i--)
		{
			int x = str[i] - 48;
			temp = temp * 10 + x;
		}
		if (!isP[temp])
			return false;
	}
	return true;
}

int main()
{
	sieve();
	int n;
	while (cin >> n && n)
	{
		int start = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
		if (prime[start] < n)
			start++;
		int power = floor(log10(n) + 1), end = pow(10, power), res, brk = 0;
		bool found = false;
		for (int i = start; prime[i] < end; i++, brk++)
		{
			if (prime[i] <= n)
				continue;
			if (check(prime[i]))
			{
				found = true;
				res = prime[i];
				break;
			}
			if (brk >= 10000)
				break;
		}
		if (found)
			cout << res << endl;
		else
			cout << 0 << endl;
	}
}
