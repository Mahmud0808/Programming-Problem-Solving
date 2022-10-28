#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

#define ll long long int

ll convert2dec(string & s, int base)
{
	ll total = 0, b = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (isdigit(s[i]))
			total += (s[i] - '0') * b;
		else
			total += (s[i] - 'A' + 10) * b;
		b *= base;
	}
	return total;
}

string convert2other(ll num, int base)
{
	string res;
	while (num)
	{
		if (num % base >= 10)
			res += (char)((num % base) + 'A' - 10);
		else
			res += to_string(num % base);
		num /= base;
	}
	if (res.empty())
		return "0";
	else
		reverse(res.begin(), res.end());
	return res;
}

bool legal(string & s, int base)
{
	int sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		if (isdigit(s[i]))
		{
			if (s[i] - '0' >= base)
				return false;
		}
		else
		{
			if (s[i] - 'A' + 10 >= base)
				return false;
		}
	}
	return true;
}

int main()
{
	int base1, base2;
	string s;
	while (cin >> base1 >> base2 >> s)
	{
		if (!legal(s, base1))
		{
			cout << s << " is an illegal base " << base1 << " number" << endl;
			continue;
		}
		cout << s << " base " << base1 << " = " << convert2other(convert2dec(s, base1), base2) << " base " << base2 << endl;
	}
}
