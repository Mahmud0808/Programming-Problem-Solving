#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll convert2decimal(int m, int base)
{
	ll num=0, i=0;
	while (m)
	{
		num += (m%10 * pow(base, i++));
		m /= 10;
	}
	return num;
}

int main()
{
	int b, m;
	string p;
	while (cin >> b && b)
	{
		cin >> p >> m;
		m = convert2decimal(m, b);
		ll num=0, sz=p.size();
		for (int i=0; i<sz; i++)
		{
			num = ((num * b) + (p[i] - '0')) % m;
		}
		if (!num)
		{
			cout << 0 << endl;
			continue;
		}
		vector <ll> res;
		while (num)
		{
			res.push_back(num % b);
			num /= b;
		}
		reverse(res.begin(), res.end());
		for (auto it: res)
			cout << it;
		cout << endl;
	}
}
