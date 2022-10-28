#include <iostream>
using namespace std;

char board[10][10];
bool found;

bool isValid(int x, int y, char ch)
{
	for (int i = 0; i < 9; i++)
		if (board[x][i] == ch || board[i][y] == ch)
			return false;
	x = (x / 3) * 3;
	y = (y / 3) * 3;
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			if (board[i][j] == ch)
				return false;
	return true;
}

void solve(int x, int y);

void bestSolution(int &x, int &y)
{
	int count = 0, _min = 1000;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				count = 0;
				for (int k = 1; k <= 9; k++)
				{
					if (isValid(i, j, (k + '0')))
						count++;
				}
				if (count < _min)
				{
					_min = count;
					x = i;
					y = j;
				}
			}
		}
	}
	if (_min > 9)
		solve(8, 9);
}

void solve(int x, int y)
{
	if (y > 8)
	{
		x++;
		y = 0;
	}
	if (x > 8)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
		found = true;
	}
	else
	{
		if (!found)
			bestSolution(x, y);
		if (board[x][y] != '.')
			return;
		for (int k = 1; k <= 9; k++)
		{
			if (isValid(x, y, (k + '0')))
			{
				board[x][y] = (k + '0');
				solve(x, y);
				if (found)
					break;
				board[x][y] = '.';
			}
		}
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, cs = 1;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		cin.ignore();
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> board[i][j];
			}
		}
		found = false;
		cout << "Case " << cs++ << ":\n";
		solve(0, 0);
	}
}
