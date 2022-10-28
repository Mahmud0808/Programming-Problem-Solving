#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int T, N, t, x, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> N;
		map < int, int >tpos;
		vector < int >time;
		for (int i = 0; i < N; i++)
		{
			cin >> t >> x;
			tpos[t] = x;
			time.push_back(t);
		}
		sort(time.begin(), time.end());
		double max = 0.0;
		for (int i = 1; i < time.size(); i++)
		{
			if ((double)abs(tpos[time[i - 1]] - tpos[time[i]]) / abs(time[i - 1] - time[i]) > max)
			{
				max = (double)abs(tpos[time[i - 1]] - tpos[time[i]]) / abs(time[i - 1] - time[i]);
			}
		}
		cout << "Case #" << cs++ << ": " << fixed << setprecision(2) << max << endl;
	}
}