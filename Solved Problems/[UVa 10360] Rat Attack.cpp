#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, d, n, x, y, size;
	cin >> t;
	while (t--)
	{
		cin >> d >> n;
		int field[1026][1026]={0};
		while (n--)
		{
			cin >> x >> y >> size;
			for (int i=max(0, x-d); i<=min(1024, x+d); i++)
			{
				for (int j=max(0, y-d); j<=min(1024, y+d); j++)
				{
					field[i][j]+=size;
				}
			}
		}
		int killed=0, posx, posy;
		for (int i=0; i<1025; i++)
		{
			for (int j=0; j<1025; j++)
			{
				if (field[i][j]>killed)
				{
					killed=field[i][j];
					posx=i;
					posy=j;
				}
			}
		}
		cout << posx << ' ' << posy << ' ' << killed << endl;
	}
}