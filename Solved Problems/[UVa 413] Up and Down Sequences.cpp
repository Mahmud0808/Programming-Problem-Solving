#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int arr[30];
	while (cin >> arr[0] && arr[0])
	{
		int i = 0;
		bool u = false, d = false;
		int up = 0, down = 0, equal = 0, N = 1, ud = 0, du = 0;
		while (cin >> arr[++i] && arr[i])
		{
			N++;
			if (arr[i] == arr[i - 1])
			{
				equal++;
				if (d)
				{
					down += equal;
					equal = 0;
				}
				else if (u)
				{
					up += equal;
					equal = 0;
				}
			}
			else if (arr[i] > arr[i - 1])
			{
				if (!u)
					du++;
				u = true, d = false;
				if (equal)
				{
					up += equal;
					equal = 0;
				}
				up++;
			}
			else
			{
				if (!d)
					ud++;
				d = true, u = false;
				if (equal)
				{
					down += equal;
					equal = 0;
				}
				down++;
			}
		}
		double UP = du == 0 ? 0.0 : (double)up / du;
		double DOWN = ud == 0 ? 0.0 : (double)down / ud;
		cout << "Nr values = " << N << ":  " << fixed << setprecision(6) << UP << ' ' << fixed <<
			setprecision(6) << DOWN << endl;
	}
}
