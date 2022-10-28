#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

ll toDecimal(ll N, int base)
{
	ll num = 0, tmp = 1;
	while (N)
	{
		num += (N % 10) * tmp;
		tmp *= base;
		N /= 10;
	}
	return num;
}

int main()
{
	ll num, tmp;
	while (cin >> num && num)
	{
		int base = 2;
		tmp = num;
		while (tmp)
		{
			if (tmp % 10 >= base)
				base = tmp % 10 + 1;
			tmp /= 10;
		}
		ll temp, sq;
		for (int i = base; i < 100; i++)
		{
			temp = toDecimal(num, i);
			sq = sqrt(temp);
			if (sq * sq == temp)
			{
				cout << i << endl;
				break;
			}
		}
	}
}