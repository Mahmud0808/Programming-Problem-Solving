#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

bitset < 10001 > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 10001; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 10001; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

bool check(int n)
{
	if (n == 0 || n == 1)
		return false;
	int sq = sqrt(n), count = 0;
	for (int i = 1; i <= sq; i++)
	{
		if (n % i == 0)
		{
			count++;
			if (n / i != i)
				count++;
		}
	}
	return isPrime[count];
}

int main()
{
	sieve();
	int T, L, H;
	cin >> T;
	while (T--)
	{
		cin >> L >> H;
		bool space = false, notfound = true;
		for (int i = L; i <= H; i++)
		{
			if (isPrime[i])
			{
				if (space)
					cout << ' ';
				cout << i;
				notfound = false;
				if (!space)
					space = true;
			}
			else if (check(i))
			{
				if (space)
					cout << ' ';
				cout << i;
				notfound = false;
				if (!space)
					space = true;
			}
		}
		if (notfound)
			cout << -1;
		cout << endl;
	}
}
