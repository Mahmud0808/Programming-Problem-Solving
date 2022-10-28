#include <iostream>
#include <climits>
using namespace std;

struct tuple
{
	int first, second, third;
} num;

int main()
{
	int T, R, H;
	while (cin >> T >> R >> H)
	{
		int TR[T][R + 1], RH[R][H + 1], HT[H][T + 1], P = INT_MAX;
		bool solution = false;
		for (int i = 0; i < T; i++)
		{
			for (int j = 0; j < R + 1; j++)
			{
				cin >> TR[i][j];
			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < H + 1; j++)
			{
				cin >> RH[i][j];
			}
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < T + 1; j++)
			{
				cin >> HT[i][j];
			}
		}
		for (int i = 0; i < T; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < H; k++)
				{
					if (!TR[i][j + 1] && !RH[j][k + 1] && !HT[k][i + 1])
					{
						if (P > TR[i][0] + RH[j][0] + HT[k][0])
						{
							P = TR[i][0] + RH[j][0] + HT[k][0];
							solution = true;
							num.first = i;
							num.second = j;
							num.third = k;
						}
					}
				}
			}
		}
		if (solution)
			cout << num.first << ' ' << num.second << ' ' << num.third << ':' << P << endl;
		else
			cout << "Don't get married!" << endl;
	}
}
