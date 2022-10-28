#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char sum(char a, char b)
{
	if (a == 'V')
		return b;
	else if (b == 'V')
		return a;
	else if (a == 'U')
	{
		if (b == 'V')
			return 'U';
		else if (b == 'U')
			return 'C';
		else if (b == 'C')
			return 'D';
		else if (b == 'D')
			return 'V';
	}
	else if (b == 'U')
	{
		if (a == 'V')
			return 'U';
		else if (a == 'U')
			return 'C';
		else if (a == 'C')
			return 'D';
		else if (a == 'D')
			return 'V';
	}
	else if (a == 'C')
	{
		if (b == 'V')
			return 'C';
		else if (b == 'U')
			return 'D';
		else if (b == 'C')
			return 'V';
		else if (b == 'D')
			return 'U';
	}
	else if (b == 'C')
	{
		if (a == 'V')
			return 'C';
		else if (a == 'U')
			return 'D';
		else if (a == 'C')
			return 'V';
		else if (a == 'D')
			return 'U';
	}
	else if (a == 'D')
	{
		if (b == 'V')
			return 'D';
		else if (b == 'U')
			return 'V';
		else if (b == 'C')
			return 'U';
		else if (b == 'D')
			return 'C';
	}
	else if (b == 'D')
	{
		if (a == 'V')
			return 'D';
		else if (a == 'U')
			return 'V';
		else if (a == 'C')
			return 'U';
		else if (a == 'D')
			return 'C';
	}
}

char carry(char a, char b)
{
	if (a == '0')
		return b;
	else if (b == '0')
		return a;
	if (a == 'C' && b == 'C')
		return 'U';
	else if (a == 'U' && b == 'D' || a == 'D' && b == 'U')
		return 'U';
	else if (a == 'D' && b == 'D')
		return 'U';
	else if (a == 'C' && b == 'D' || a == 'D' && b == 'C')
		return 'U';
	else
		return '0';
}

string operationA(string A, string B)
{
	int sz1 = A.size(), sz2 = B.size();
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	char carr = '0';
	string num;
	for (int i = 0; i < min(sz1, sz2); i++)
	{
		if (carr == '0')
		{
			num += sum(A[i], B[i]);
			carr = carry(A[i], B[i]);
		}
		else
		{
			num += sum(sum(A[i], B[i]), carr);
			if (carry(A[i], B[i]) != 0 && carry(carry(A[i], B[i]), carr) == '0')
				carr = carry(A[i], B[i]);
			else
				carr = carry(sum(A[i], B[i]), carr);
		}
	}
	if (sz1 > sz2)
	{
		for (int i = min(sz1, sz2); i < max(sz1, sz2); i++)
		{
			if (carr == '0')
				break;
			else
			{
				num += sum(A[i], carr);
				carr = carry(A[i], carr);
			}
		}
	}
	else if (sz1 < sz2)
	{
		for (int i = min(sz1, sz2); i < max(sz1, sz2); i++)
		{
			if (carr == '0')
				break;
			else
			{
				num += sum(B[i], carr);
				carr = carry(B[i], carr);
			}
		}
	}
	if (carr != '0')
		num += carr;
	reverse(num.begin(), num.end());
	return num;
}

string operationR(string s)
{
	s.pop_back();
	string temp = "V";
	temp += s;
	return temp;
}

string operationL(string s)
{
	s += "V";
	return s;
}

int main()
{
	int N;
	cin >> N;
	string num1, num2, op, res, tmp, temp1, temp2;
	cout << "COWCULATIONS OUTPUT" << endl;
	while (N--)
	{
		cin >> num1 >> num2;
		int n = 3;
		while (n--)
		{
			cin >> op;
			if (op == "A")
			{
				num2 = operationA(num1, num2);
			}
			else if (op == "R")
			{
				num2 = operationR(num2);
			}
			else if (op == "L")
			{
				num2 = operationL(num2);
			}
			else if (op == "N")
			{
				continue;
			}
		}
		if (num2.size() < 8)
		{
			for (int i = num2.size(); i < 8; i++)
			{
				tmp += "V";
			}
			tmp += num2;
			num2 = tmp;
		}
		cin >> res;
		if (num2 == res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		tmp.clear();
	}
	cout << "END OF OUTPUT" << endl;
}
