#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N, wall[9][9];
	cin >> N;
	while (N--)
	{
		memset(wall, -1, sizeof(wall));
		for (int i = 0; i < 9; i += 2)
		{
			for (int j = 0; j <= i; j += 2)
			{
				cin >> wall[i][j];
			}
		}
		for (int i = 8; i >= 2; i -= 2)
		{
			for (int j = 1, k = 0, l = 0; j < i; j += 2, l += 2)
			{
				wall[i][j] = (wall[i - 2][l] - wall[i][j - 1] - wall[i][j + 1]) / 2;
				wall[i - 1][k++] = wall[i][j - 1] + wall[i][j];
				wall[i - 1][k++] = wall[i][j] + wall[i][j + 1];
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j)
					cout << ' ';
				if (wall[i][j] != -1)
					cout << wall[i][j];
			}
			cout << endl;
		}
	}
}