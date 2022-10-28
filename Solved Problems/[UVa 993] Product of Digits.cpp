#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t, N;
	vector < int >res;
	cin >> t;
	while (t--)
	{
		cin >> N;
		res.clear();
		if (N == 0 || N == 1)
		{
			cout << N << endl;
			continue;
		}
		for (int i = 9; i >= 2; i--)
		{
			if (N % i == 0)
			{
				while (N % i == 0)
				{
					N /= i;
					res.push_back(i);
				}
			}
		}
		if (N != 1)
		{
			cout << -1 << endl;
			continue;
		}
		sort(res.begin(), res.end());
		int sz = res.size();
		for (int i = 0; i < sz; i++)
		{
			cout << res[i];
		}
		cout << endl;
	}
}
