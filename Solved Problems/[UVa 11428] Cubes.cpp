#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < long long int >xy;

void preCalc()
{
	for (int i = 1; i <= 10000; i++)
	{
		xy.push_back(pow(i, 3));
	}
}

bool bs(int l, int r, int val)
{
	if (l <= r)
	{
		int m = (l + r) / 2;
		if (xy[m] == val)
			return true;
		if (xy[m] < val)
			return bs(m + 1, r, val);
		else
			return bs(l, m - 1, val);
	}
	else
		return false;
}

int main()
{
	preCalc();
	int N, sz = xy.size(), x, y;
	while (cin >> N && N)
	{
		bool solution = false;
		for (int i = 0; i < sz; i++)
		{
			if (bs(0, sz - 1, xy[i] - N))
			{
				solution = true;
				x = ceil(pow(xy[i] - N, 1.0 / 3.0));
				y = ceil(pow(xy[i], 1.0 / 3.0));
				break;
			}
		}
		if (solution)
			cout << max(x, y) << ' ' << min(x, y) << endl;
		else
			cout << "No solution" << endl;
	}
}
