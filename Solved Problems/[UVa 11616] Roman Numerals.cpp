#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

int main()
{
	string num;
	int N, x;
	while (cin >> num)
	{
		if (isdigit(num[0]))
		{
			stringstream tmp(num);
			tmp >> N;
			if (N / 1000 != 0)
			{
				x = N / 1000;
				if (x >= 1)
				{
					for (int i = 0; i < x; i++)
					{
						cout << "M";
					}
					N %= 1000;
				}
			}
			if (N / 500 != 0)
			{
				x = N / 500;
				if (N >= 900)
				{
					cout << "CM";
					N -= 900;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "D";
					}
					N %= 500;
				}
			}
			if (N / 100 != 0)
			{
				x = N / 100;
				if (N >= 400)
				{
					cout << "CD";
					N -= 400;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "C";
					}
					N %= 100;
				}
			}
			if (N / 50 != 0)
			{
				x = N / 50;
				if (N >= 90)
				{
					cout << "XC";
					N -= 90;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "L";
					}
					N %= 50;
				}
			}
			if (N / 10 != 0)
			{
				x = N / 10;
				if (N >= 40)
				{
					cout << "XL";
					N -= 40;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "X";
					}
					N %= 10;
				}
			}
			if (N / 5 != 0)
			{
				x = N / 5;
				if (N >= 9)
				{
					cout << "IX";
					N -= 9;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "V";
					}
					N %= 5;
				}
			}
			if (N / 1 != 0)
			{
				x = N / 1;
				if (N >= 4)
				{
					cout << "IV";
					N -= 4;
				}
				else
				{
					for (int i = 0; i < x; i++)
					{
						cout << "I";
					}
				}
			}
			cout << endl;
		}
		else
		{
			int res = 0;
			for (int i = 0; i < num.size(); i++)
			{
				if (i != num.size() - 1 && num[i] == 'C' && num[i + 1] == 'M')
				{
					res += 900;
					i++;
				}
				else if (i != num.size() - 1 && num[i] == 'C' && num[i + 1] == 'D')
				{
					res += 400;
					i++;
				}
				else if (i != num.size() - 1 && num[i] == 'X' && num[i + 1] == 'C')
				{
					res += 90;
					i++;
				}
				else if (i != num.size() - 1 && num[i] == 'X' && num[i + 1] == 'L')
				{
					res += 40;
					i++;
				}
				else if (i != num.size() - 1 && num[i] == 'I' && num[i + 1] == 'X')
				{
					res += 9;
					i++;
				}
				else if (i != num.size() - 1 && num[i] == 'I' && num[i + 1] == 'V')
				{
					res += 4;
					i++;
				}
				else if (num[i] == 'I')
					res += 1;
				else if (num[i] == 'V')
					res += 5;
				else if (num[i] == 'X')
					res += 10;
				else if (num[i] == 'L')
					res += 50;
				else if (num[i] == 'C')
					res += 100;
				else if (num[i] == 'D')
					res += 500;
				else if (num[i] == 'M')
					res += 1000;
			}
			cout << res << endl;
		}
	}
}