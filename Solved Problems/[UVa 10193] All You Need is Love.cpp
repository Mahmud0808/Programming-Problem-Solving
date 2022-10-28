#include <iostream>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	int N, cs = 1;
	string S1, S2;
	cin >> N;
	while (N--)
	{
		cin >> S1 >> S2;
		ll num1 = 0, num2 = 0;
		for (ll i = S1.size() - 1, j = 1; i >= 0; i--, j <<= 1)
		{
			if (S1[i] == '1')
				num1 += j;
		}
		for (ll i = S2.size() - 1, j = 1; i >= 0; i--, j <<= 1)
		{
			if (S2[i] == '1')
				num2 += j;
		}
		if (gcd(num1, num2) != 1)
			cout << "Pair #" << cs++ << ": All you need is love!" << endl;
		else
			cout << "Pair #" << cs++ << ": Love is not all you need!" << endl;
	}
}
