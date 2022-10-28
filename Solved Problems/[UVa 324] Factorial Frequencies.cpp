#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
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

string factorial[1001];

void preCalc()
{
	factorial[0] = factorial[1] = "1";
	for (int i = 2; i <= 366; i++)
	{
		factorial[i] = multiply(factorial[i - 1], to_string(i));
	}
}

int main()
{
	preCalc();
	int num;
	while (cin >> num && num)
	{
		map < char, int >freq;
		int sz = factorial[num].size();
		for (int i = 0; i < sz; i++)
		{
			freq[factorial[num][i]]++;
		}
		cout << num << "! --" << endl;
		cout << "    (0)" << setw(5) << freq['0'] << "    (1)" << setw(5) << freq['1'] << "    (2)" << setw(5) << freq['2'] << "    (3)" << setw(5) << freq['3'] << "    (4)" << setw(5) << freq['4'] << endl;
		cout << "    (5)" << setw(5) << freq['5'] << "    (6)" << setw(5) << freq['6'] << "    (7)" << setw(5) << freq['7'] << "    (8)" << setw(5) << freq['8'] << "    (9)" << setw(5) << freq['9'] << endl;
	}
}
