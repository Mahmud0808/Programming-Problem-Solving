#include <iostream>
using namespace std;

int main()
{
	int T, n, t, m;
	cin >> T;
	while (T--)
	{
		cin >> n >> t >> m;
		int arrive[m];
		for (int i = 0; i < m; i++)
			cin >> arrive[i];
		int trip = 0, time = 0;
		if (n >= m)
		{
			trip++;
			time = arrive[m - 1] + t;
		}
		else if (m % n == 0)
		{
			for (int i = n - 1; i < m; i += n)
			{
				trip++;
				time = max(time, arrive[i]) + (2 * t);
			}
			time -= t;
		}
		else
		{
			trip++;
			time = max(time, arrive[(m % n) - 1]) + (2 * t);
			for (int i = (m % n) + n - 1; i < m; i += n)
			{
				trip++;
				time = max(time, arrive[i]) + (2 * t);
			}
			time -= t;
		}
		cout << time << ' ' << trip << endl;
	}
}
