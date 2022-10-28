#include <iostream>
#include <algorithm>
using namespace std;

string add(string num1, string num2)
{
	int sz1 = num1.size(), sz2 = num2.size();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string sum;
	char carry = '0';
	for (int i = 0; i < min(sz1, sz2); i++)
	{
		sum += (char)((((num1[i] - '0') + (num2[i] - '0') + (carry - '0')) % 10) + '0');
		carry = (char)((((num1[i] - '0') + (num2[i] - '0') + (carry - '0')) / 10) + '0');
	}
	if (sz1 > sz2)
	{
		for (int i = sz2; i < sz1; i++)
		{
			sum += (char)((((num1[i] - '0') + (carry - '0')) % 10) + '0');
			carry = (char)((((num1[i] - '0') + (carry - '0')) / 10) + '0');
		}
	}
	else if (sz2 > sz1)
	{
		for (int i = sz1; i < sz2; i++)
		{
			sum += (char)((((num2[i] - '0') + (carry - '0')) % 10) + '0');
			carry = (char)((((num2[i] - '0') + (carry - '0')) / 10) + '0');
		}
	}
	if (carry != '0')
		sum += carry;
	reverse(sum.begin(), sum.end());
	return sum;
}

int main()
{
	string num, total = "0";
	while (cin >> num)
	{
		if (num != "0")
			total = add(total, num);
		else
		{
			cout << total << endl;
			break;
		}
	}
}
