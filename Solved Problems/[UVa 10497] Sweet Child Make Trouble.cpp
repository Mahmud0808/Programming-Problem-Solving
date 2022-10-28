#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0")
		return "0";
	bool negative = false;
	if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
	{
		negative = true;
		if (num1[0] == '-')
			num1 = num1.substr(1);
		else if (num2[0] == '-')
			num2 = num2.substr(1);
	}
	else if (num1[0] == '-' && num2[0] == '-')
	{
		num1 = num1.substr(1);
		num2 = num2.substr(1);
	}
	if (num2.size() > num1.size())
		swap(num1, num2);
	vector < int >result(num1.size() + num2.size(), 0);
	int sum, carry, i1 = 0, i2;
	for (int i = num2.size() - 1; i >= 0; i--)
	{
		carry = 0, i2 = 0;
		if (num2[i] == '0')
		{
			i1++;
			continue;
		}
		for (int j = num1.size() - 1; j >= 0; j--)
		{
			sum = ((num1[j] - '0') * (num2[i] - '0')) + carry + result[i1 + i2];
			result[i1 + i2] = sum % 10;
			carry = sum / 10;
			i2++;
		}
		if (carry != 0)
			result[i1 + i2] = carry;
		i1++;
	}
	int idx = result.size() - 1;
	while (result[idx] == 0)
	{
		idx--;
	}
	string res;
	if (negative)
		res += '-';
	for (int i = idx; i >= 0; i--)
		res += to_string(result[i]);
	return res;
}

string add(string num1, string num2)
{
	if (num1 == "0")
		return num2;
	else if (num2 == "0")
		return num1;
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

string fibo[801];

void preCalc()
{
	fibo[0] = fibo[1] = "0", fibo[2] = "1";
	for (int i = 3; i <= 800; i++)
	{
		fibo[i] = multiply(to_string(i - 1), add(fibo[i - 1], fibo[i - 2]));
	}
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n != -1)
	{
		cout << fibo[n] << endl;
	}
}
