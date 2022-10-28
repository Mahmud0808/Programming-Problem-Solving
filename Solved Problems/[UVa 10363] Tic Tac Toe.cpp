#include <iostream>
#include <cstring>
using namespace std;

bool winCheck(string str)
{
	if (((str[0] == 'X' && str[1] == 'X' && str[2] == 'X') || (str[3] == 'X' && str[4] == 'X' && str[5] == 'X') || (str[6] == 'X' && str[7] == 'X' && str[8] == 'X') || (str[0] == 'X' && str[3] == 'X' && str[6] == 'X') || (str[1] == 'X' && str[4] == 'X' && str[7] == 'X') || (str[2] == 'X' && str[5] == 'X' && str[8] == 'X') || (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') || (str[2] == 'X' && str[4] == 'X' && str[6] == 'X')) && ((str[0] == 'O' && str[1] == 'O' && str[2] == 'O') || (str[3] == 'O' && str[4] == 'O' && str[5] == 'O') || (str[6] == 'O' && str[7] == 'O' && str[8] == 'O') || (str[0] == 'O' && str[3] == 'O' && str[6] == 'O') || (str[1] == 'O' && str[4] == 'O' && str[7] == 'O') || (str[2] == 'O' && str[5] == 'O' && str[8] == 'O') || (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') || (str[2] == 'O' && str[4] == 'O' && str[6] == 'O')))
		return true;
	else
		return false;
}

int winner(string str)
{
	if ((str[0] == 'X' && str[1] == 'X' && str[2] == 'X') || (str[3] == 'X' && str[4] == 'X' && str[5] == 'X') || (str[6] == 'X' && str[7] == 'X' && str[8] == 'X') || (str[0] == 'X' && str[3] == 'X' && str[6] == 'X') || (str[1] == 'X' && str[4] == 'X' && str[7] == 'X') || (str[2] == 'X' && str[5] == 'X' && str[8] == 'X') || (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') || (str[2] == 'X' && str[4] == 'X' && str[6] == 'X'))
		return 1;
	else if ((str[0] == 'O' && str[1] == 'O' && str[2] == 'O') || (str[3] == 'O' && str[4] == 'O' && str[5] == 'O') || (str[6] == 'O' && str[7] == 'O' && str[8] == 'O') || (str[0] == 'O' && str[3] == 'O' && str[6] == 'O') || (str[1] == 'O' && str[4] == 'O' && str[7] == 'O') || (str[2] == 'O' && str[5] == 'O' && str[8] == 'O') || (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') || (str[2] == 'O' && str[4] == 'O' && str[6] == 'O'))
		return 2;
	else
		return 0;
}

int main()
{
	int N;
	string line1, line2, line3;
	cin >> N;
	while (N--)
	{
		string str;
		str.clear();
		int X = 0, O = 0;
		cin >> line1 >> line2 >> line3;
		str.append(line1);
		str.append(line2);
		str.append(line3);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'X')
				X++;
			if (str[i] == 'O')
				O++;
		}
		if (winCheck(str))
			cout << "no" << endl;
		else
		{
			if (X == O)
			{
				if (winner(str)==1)
					cout << "no" << endl;
				else
					cout << "yes" << endl;
			}
			else if (X - 1 == O)
			{
				if (winner(str)==2)
					cout << "no" << endl;
				else
					cout << "yes" << endl;
			}
			else
				cout << "no" << endl;
		}
	}
}