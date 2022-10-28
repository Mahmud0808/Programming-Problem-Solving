#include <iostream>
#include <bitset>
#include <vector>
#include <map>
using namespace std;

#define maxN 1000005

vector < int >prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	prime.push_back(2);
	for (int i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	int m = 0, d = 1;
	for (int i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
	}
}

int main()
{
	sieve();
	int T, L, U;
	cin >> T;
	while (T--)
	{
		cin >> L >> U;
		int left = lower_bound(prime.begin(), prime.end(), L) - prime.begin() + 1;
		int right = lower_bound(prime.begin(), prime.end(), U) - prime.begin();
		if (L < prime[left])
			left--;
		if (U < prime[right])
			right--;
		map < int, int >counter;
		int max = -1, num;
		for (int i = left; i <= right - 1; i++)
		{
			counter[prime[i + 1] - prime[i]]++;
		}
	  for (auto it:counter)
		{
			if (it.second > max)
			{
				max = it.second;
				num = it.first;
			}
		}
		if (max != -1)
		{
		  for (auto it:counter)
			{
				if (it.second == max && num != it.first)
				{
					max = -1;
					break;
				}
			}
		}
		if (max != -1)
			cout << "The jumping champion is " << num << endl;
		else
			cout << "No jumping champion" << endl;
	}
}
