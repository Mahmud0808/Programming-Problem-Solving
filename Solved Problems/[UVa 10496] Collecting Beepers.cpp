#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, X, Y, path, result;

struct beeper
{
	int x, y;
} tmp;

void solve(int l, int r, vector < beeper > beep)
{
	if (l == r)
	{
		path += abs(beep[0].x - X) + abs(beep[0].y - Y);
		for (int i = 1; i < n; i++)
		{
			path += abs(beep[i - 1].x - beep[i].x) + abs(beep[i - 1].y - beep[i].y);
		}
		path += abs(beep[n - 1].x - X) + abs(beep[n - 1].y - Y);
		if (path < result)
		{
			result = path;
		}
		path = 0;
	}
	for (int i = l; i <= r; i++)
	{
		swap(beep[l], beep[i]);
		solve(l + 1, r, beep);
		swap(beep[l], beep[i]);
	}
}

int main()
{
	int t, xsize, ysize;
	cin >> t;
	while (t--)
	{
		cin >> xsize >> ysize;
		cin >> X >> Y;
		cin >> n;
		vector < beeper > beep;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp.x >> tmp.y;
			beep.push_back(tmp);
		}
		path = 0, result = 1e6;
		solve(0, n - 1, beep);
		cout << "The shortest path has length " << result << endl;
		beep.clear();
	}
}
