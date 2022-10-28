#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		int T[N];
		for (int i = 0; i < N; i++)
		{
			cin >> T[i];
		}
		sort(T, T + N);
		int diff = 0, total = 0;
		for (int i = 0; i < N; i += 2)
		{
			diff += min(abs(T[i] - T[i + 1]), (24 - abs(T[i] - T[i + 1])));
		}
		total = diff;
		diff = min(abs(T[0] - T[N - 1]), (24 - abs(T[0] - T[N - 1])));
		for (int i = 1; i < N - 1; i += 2)
		{
			diff += min(abs(T[i] - T[i + 1]), (24 - abs(T[i] - T[i + 1])));
		}
		total = min(total, diff);
		cout << total << endl;
	}
}
