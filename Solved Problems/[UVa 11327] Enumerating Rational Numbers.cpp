#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 200005
#define ll long long int

ll phi[maxN];

void preCalc()
{
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i < maxN; i++)
	{
		if (phi[i] == 0)
		{
			phi[i] = i - 1;
			for (int j = 2 * i; j < maxN; j += i)
			{
				if (phi[j] == 0)
					phi[j] = j;
				phi[j] -= (phi[j] / i);
			}
		}
		phi[i] += phi[i - 1];
	}
}

int gcd(int a, int b)
{
	return !a ? b : gcd(b % a, a);
}

int main()
{
	preCalc();
	ll k;
	while (cin >> k && k)
	{
		if (k == 1)
		{
			cout << 0 << '/' << 1 << endl;
			continue;
		}
		int denominator = lower_bound(phi, phi + maxN, k - 1) - phi;
		int cnt = k - 1 - phi[denominator - 1], count = 0;
		for (int i = 1; i <= denominator; i++)
		{
			if (gcd(i, denominator) == 1)
				count++;
			if (cnt == count)
			{
				cout << i << '/' << denominator << endl;
				break;
			}
		}
	}
}
