#include <iostream>
#include <climits>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	int n, t;
	while (cin >> n >> t && (n && t))
	{
		int coin[n], height;
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
		}
		while (t--)
		{
			cin >> height;
			int minHeight = INT_MIN, maxHeight = INT_MAX, LCM, avg;
			for (int i = 0; i < n - 3; i++)
			{
				for (int j = i + 1; j < n - 2; j++)
				{
					for (int k = j + 1; k < n - 1; k++)
					{
						for (int l = k + 1; l < n; l++)
						{
							LCM = lcm(coin[i], lcm(coin[j], lcm(coin[k], coin[l])));
							avg = height / LCM;
							if (avg * LCM <= height)
								minHeight = max(minHeight, avg * LCM);
							if (avg * LCM >= height)
								maxHeight = min(maxHeight, avg * LCM);
							else
								maxHeight = min(maxHeight, (avg + 1) * LCM);

						}
					}
				}
			}
			if (minHeight > height || minHeight == INT_MIN)
				minHeight = 0;
			cout << minHeight << ' ' << maxHeight << endl;
		}
	}
}
