#include <iostream>
#include <iomanip>
using namespace std;

int x, y, cs, board[10][10];

bool isValid(int a, int b)
{
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i--, j--)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i--, j++)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i++, j--)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i++, j++)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i++)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; i--)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; j++)
	{
		if (board[i][j])
			return false;
	}
	for (int i = a, j = b; i > 0 && j > 0 && i <= 8 && j <= 8; j--)
	{
		if (board[i][j])
			return false;
	}
	return true;
}

void solve(int idx)
{
	if (idx > 8)
	{
		/* debugging bool space; for (int i = 1; i <= 8; i++) { space = false;
		   for (int j = 1; j <= 8; j++) { if (space) cout << ' '; cout <<
		   board[i][j]; space = true; } cout << endl; } cout << endl << endl; */
		cout << setw(2) << cs++ << "      ";
		bool space = false;
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
			{
				if (board[j][i])
				{
					if (space)
						cout << ' ';
					cout << j;
					space = true;
				}
			}
		}
		cout << endl;
		return;
	}
	if (idx == y)
		solve(idx + 1);
	else
		for (int i = 1; i <= 8; i++)
		{
			if (!board[i][idx] && isValid(i, idx))
			{
				board[i][idx] = 1;
				solve(idx + 1);
				board[i][idx] = 0;
			}
		}
}

int main()
{
	int t;
	cin >> t;
	bool newline = false;
	while (t--)
	{
		cin >> x >> y;
		board[x][y] = 1, cs = 1;
		if (newline)
			cout << endl;
		else
			newline = true;
		cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl << endl;
		solve(1);
		board[x][y] = 0;
	}
}
