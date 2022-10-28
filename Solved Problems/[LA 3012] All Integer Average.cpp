#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int isInt(float N)
{
	return (int)((N * 100) / 100);
}

int findgcd(int a, int b)
{
	if (a == 0)
		return a;
	if (b == 0)
		return b;
	if (a == b)
		return a;
	if (a > b)
		return findgcd(a - b, b);
	else
		return findgcd(a, b - a);
}

int main()
{
	int n, a, b, c, gcd, cs = 1;
	while (cin >> n && n)
	{
		cout << "Case " << cs++ << ":" << endl;
		double sum = 0.0, num, d = n;
		int sp = 0;
		while (d--)
		{
			cin >> num;
			sum += num;
		}
		if (sum / n == isInt(sum / n))
		{
			if (sum / n >= 0)
				cout << (int)(sum / n) << endl;
			else
				cout << "- " << abs((int)(sum / n)) << endl;
		}
		else
		{
			if (sum >= 0 && abs(sum / n) > 1)
			{
				gcd = findgcd(sum, n);
				sum /= gcd;
				n /= gcd;
				a = sum / n;
				b = sum - (a * n);
				c = n;
				for (int i = 0;
					 i < floor(log10(a) + 1) + floor(log10(c) + 1) - floor(log10(b) + 1); i++)
					cout << ' ';
				cout << b << endl;
				if (a != 0)
					cout << a;
				for (int i = 0; i < floor(log10(c) + 1); i++)
					cout << '-';
				cout << endl;
				for (int i = 0; i < floor(log10(a) + 1); i++)
					cout << ' ';
				cout << c << endl;
			}
			else if (sum < 0 && abs(sum / n < 1))
			{
				sum = abs(sum);
				gcd = findgcd(sum, n);
				sum /= gcd;
				n /= gcd;
				a = sum / n;
				b = sum - (a * n);
				c = n;
				if (a == 0)
					sp = 2;
				else
					sp = log10(a) + 3;
				for (int i = 0; i < sp + floor(log10(c) + 1) - floor(log10(b) + 1); i++)
					cout << ' ';
				cout << b << endl;
				cout << "- ";
				if (a != 0)
					cout << a;
				for (int i = 0; i < floor(log10(c) + 1); i++)
					cout << '-';
				cout << endl;
				for (int i = 0; i < sp; i++)
					cout << ' ';
				cout << c << endl;
			}
			else
			{
				gcd = findgcd(sum, n);
				sum /= gcd;
				n /= gcd;
				b = sum;
				c = n;
				for (int i = 0; i < floor(log10(c) + 1) - floor(log10(b) + 1); i++)
					cout << ' ';
				cout << b << endl;
				for (int i = 0; i < floor(log10(c) + 1); i++)
					cout << '-';
				cout << endl;
				cout << c << endl;
			}
		}
	}
}