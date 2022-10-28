#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

#define ll long long int

int __gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	return __gcd(b % a, a);
}

int main()
{
	int j, cs = 1;
	string s;
	while (cin >> j && j != -1)
	{
		cin >> s;
		stringstream num(s);
		ll numerator, denominator;
		long double X;
		num >> X;
		if (j == 0 && X == 0.0)
		{
			cout << "Case " << cs++ << ": " << 0 << '/' << 1 << endl;
			continue;
		}
		else if (j == 0)
		{
			s.erase(0, 2);
			stringstream tmp(s);
			tmp >> numerator;
			denominator = pow(10, s.size());
			ll gcd = __gcd(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;
			if (numerator == 0 && denominator == 0)
				numerator = denominator = 1;
			cout << "Case " << cs++ << ": " << numerator << '/' << denominator << endl;
			continue;
		}
		int k = s.size() - 2 - j;
		numerator = ceil(pow(10, k + j) * X - pow(10, k) * X);
		denominator = ceil(pow(10, k + j) - pow(10, k));
		ll gcd = __gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		cout << "Case " << cs++ << ": " << numerator << '/' << denominator << endl;
	}
}
