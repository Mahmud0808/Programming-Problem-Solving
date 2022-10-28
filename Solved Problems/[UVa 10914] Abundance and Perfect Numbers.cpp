#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long int
#define maxN 10000005

bitset < maxN > isPrime;

struct oddprime
{
	int num;
	ll divs;
} tmp;

vector < oddprime > aod;

int divSum(int n)
{
	int sum = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			sum += i;
			if (i != n / i)
				sum += (n / i);
		}
	}
	return sum;
}

bool cmp(oddprime a, oddprime b)
{
	return (a.num < b.num);
}

void preCalc()
{
	isPrime.set();
	for (int i = 2; i < maxN; i += 2)
		isPrime[i] = false;
	for (int i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
		{
			for (int j = 2; i * j < maxN; j <<= 1)
			{
				tmp.num = i * j;
				tmp.divs = ((i + 1) * ((2 * j) - 1)) - (2 * i * j);
				aod.push_back(tmp);
			}
			if (i < 3500)
			{
				for (int j = i * i; j < maxN; j += 2 * i)
					isPrime[j] = false;
			}
		}
	}
	sort(aod.begin(), aod.end(), cmp);
	int sz = aod.size();
	for (int i = 1; i < sz; i++)
	{
		aod[i].divs += aod[i - 1].divs;
	}
}

int bs(int n)
{
	int low = 0, mid, high = 737057;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (aod[mid].num > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (aod[mid].num > n)
		mid--;
	return mid;
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n)
	{
		if (n < 10)
		{
			cout << n << ' ' << aod[0].divs << endl;
			continue;
		}
		int idx = bs(n);
		ll res = aod[idx].divs;
		cout << n << ' ' << res << endl;
	}
}
