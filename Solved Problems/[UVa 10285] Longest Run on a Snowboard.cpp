#include <bits/stdc++.h>
using namespace std;

int area[105][105], len[105][105], R, C;

int backtrack(int x, int y)
{
	if (len[x][y])
		return len[x][y];
	int up = 0, down = 0, left = 0, right = 0;
	if (x > 0 && (area[x-1][y] < area[x][y]))
		up = backtrack(x-1, y)+1;
	if (x < R-1 && (area[x+1][y] < area[x][y]))
		down = backtrack(x+1, y)+1;
	if (y > 0 && (area[x][y-1] < area[x][y]))
		left = backtrack(x, y-1)+1;
	if (y < C-1 && (area[x][y+1] < area[x][y]))
		right = backtrack(x, y+1) + 1;
	return len[x][y] = max(up, max(down, max(left, right)));
}

int main()
{
	int N;
	string name;
	cin >> N;
	while (N--)
	{
		cin >> name >> R >> C;
		memset(len, 0, sizeof(len));
		for (int i=0; i<R; i++)
		{
			for (int j=0; j<C; j++)
			{
				cin >> area[i][j];
			}
		}
		int max = 0;
		for (int i=0; i<R; i++)
		{
			for (int j=0; j<C; j++)
			{
				int length = backtrack(i, j);
				if (length > max)
					max = length;
			}
		}
		cout << name << ": " << max + 1 << endl;
	}
}