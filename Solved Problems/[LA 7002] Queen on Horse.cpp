#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int n, cnt, board[20][20];

bool isValid(int x, int y)
{
	for (int i = 0; i < n; i++)
		if (board[x][i])
			return false;
	for (int i = 0; i < n; i++)
		if (board[i][y])
			return false;
	for (int i = x, j = y; i >= 0 && j >= 0 && i < n && j < n; i++, j++)
		if (board[i][j])
			return false;
	for (int i = x, j = y; i >= 0 && j >= 0 && i < n && j < n; i--, j--)
		if (board[i][j])
			return false;
	for (int i = x, j = y; i >= 0 && j >= 0 && i < n && j < n; i++, j--)
		if (board[i][j])
			return false;
	for (int i = x, j = y; i >= 0 && j >= 0 && i < n && j < n; i--, j++)
		if (board[i][j])
			return false;
	if (x - 2 >= 0 && y + 1 < n)
		if (board[x - 2][y + 1])
			return false;
	if (x - 2 >= 0 && y - 1 >= 0)
		if (board[x - 2][y - 1])
			return false;
	if (x - 1 >= 0 && y + 2 < n)
		if (board[x - 1][y + 2])
			return false;
	if (x - 1 >= 0 && y - 2 >= 0)
		if (board[x - 1][y - 2])
			return false;
	if (x + 2 < n && y + 1 < n)
		if (board[x + 2][y + 1])
			return false;
	if (x + 2 < n && y - 1 >= 0)
		if (board[x + 2][y - 1])
			return false;
	if (x + 1 < n && y + 2 < n)
		if (board[x + 1][y + 2])
			return false;
	if (x + 1 < n && y - 2 >= 0)
		if (board[x + 1][y - 2])
			return false;
	if (x - 4 >= 0 && y + 2 < n)
		if (board[x - 4][y + 2])
			return false;
	if (x - 4 >= 0 && y - 2 >= 0)
		if (board[x - 4][y - 2])
			return false;
	if (x - 2 >= 0 && y + 4 < n)
		if (board[x - 2][y + 4])
			return false;
	if (x - 2 >= 0 && y - 4 >= 0)
		if (board[x - 2][y - 4])
			return false;
	if (x + 4 < n && y + 2 < n)
		if (board[x + 4][y + 2])
			return false;
	if (x + 4 < n && y - 2 >= 0)
		if (board[x + 4][y - 2])
			return false;
	if (x + 2 < n && y + 4 < n)
		if (board[x + 2][y + 4])
			return false;
	if (x + 2 < n && y - 4 >= 0)
		if (board[x + 2][y - 4])
			return false;
	return true;
}

map < int, int >counter;

void solve(int x, int y)
{
	if (x == n)
	{
		/* Debugging
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl; */
		counter[cnt]++;
		return;
	}
	for (int i = x; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isValid(i, j))
			{
				board[i][j] = 1;
				cnt++;
				solve(i, j + 1);
				board[i][j] = 0;
				cnt--;
			}
		}
	}
	solve(n, 0);
}

int main()
{
	int N, t, x, y, max;
	cin >> N;
	while (N--)
	{
		cin >> n >> t;
		max = cnt = t;
		while (t--)
		{
			cin >> x >> y;
			board[x][y] = 1;
		}
		solve(0, 0);
	  for (auto it:counter)
		{
			if (it.first > max)
				max = it.first;
		}
		cout << max << ' ' << counter[max] << endl;
		memset(board, 0, sizeof(board));
		counter.clear();
	}
}
