#include <iostream>
using namespace std;

int n, cnt, _max;
char board[4][4];

bool isValid(int x, int y)
{
	for (int i = x + 1; i < n; i++)
	{
		if (board[i][y] == 'X')
			break;
		else if (board[i][y] == '!')
			return false;
	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (board[i][y] == 'X')
			break;
		else if (board[i][y] == '!')
			return false;
	}
	for (int i = y + 1; i < n; i++)
	{
		if (board[x][i] == 'X')
			break;
		else if (board[x][i] == '!')
			return false;
	}
	for (int i = y - 1; i >= 0; i--)
	{
		if (board[x][i] == 'X')
			break;
		else if (board[x][i] == '!')
			return false;
	}
	return true;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '.' && isValid(i, j))
			{
				board[i][j] = '!';
				cnt++;
				if (cnt > _max)
				{
					_max = cnt;
				}
				solve();
				cnt--;
				board[i][j] = '.';
			}
		}
	}
}

int main()
{
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
		}
		cnt = 0, _max = 0;
		solve();
		cout << _max << endl;
	}
}
