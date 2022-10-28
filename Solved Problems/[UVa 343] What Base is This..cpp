#include <iostream>
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

int findBase(string & s)
{
	int base = 0, sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		if (isdigit(s[i]))
		{
			if (s[i] - '0' > base)
				base = s[i] - '0';
		}
		else
		{
			if (s[i] - 'A' + 10 > base)
				base = s[i] - 'A' + 10;
		}
	}
	return base;
}

int main()
{
	string n1, n2;
	while (cin >> n1 >> n2)
	{
		if (n1 == "0" && n2 == "0")
		{
			cout << "0 (base 2) = 0 (base 2)" << endl;
			continue;
		}
		int base1, base2, tmp;
		base1 = findBase(n1) + 1;
		tmp = base2 = findBase(n2) + 1;
		bool possible = false;
		for (; base1 <= 36; base1++)
		{
			for (base2 = tmp; base2 <= 36; base2++)
			{
				if (convert2dec(n1, base1) == convert2dec(n2, base2))
				{
					possible = true;
					break;
				}
			}
			if (possible)
				break;
		}
		if (!possible)
			cout << n1 << " is not equal to " << n2 << " in any base 2..36" << endl;
		else
			cout << n1 << " (base " << base1 << ") = " << n2 << " (base " << base2 << ")" << endl;
	}
}
