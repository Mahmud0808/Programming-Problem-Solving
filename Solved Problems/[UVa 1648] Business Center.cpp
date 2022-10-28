#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n, m, u, d;
	while (cin >> n >> m)
	{
		int res = INT_MAX, reach;
		while (m--)
		{
			cin >> u >> d;
			int low = 0, high = n, mid;
			while (low <= high)
			{
				mid = (low + high) / 2;
				reach = mid * u - (n - mid) * d;
				if (reach > 0)
				{
					high = mid - 1;
					res = min(res, reach);
				}
				else
					low = mid + 1;
			}
		}
		cout << res << endl;
	}
}