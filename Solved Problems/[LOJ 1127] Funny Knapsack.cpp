#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define lld long long unsigned int

int main()
{
	lld T, n, W, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> n >> W;
		lld arr[n], count = 0, total = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int half1 = ceil((float)n / 2.0), half2 = n - half1;
		lld left[1 << half1], right[1 << half2];
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		for (int i = 0; i < (1 << half1); i++)
		{
			for (int j = 0; j < half1; j++)
			{
				if (i & (1 << j))
				{
					left[i] += arr[j];
				}
			}
		}
		for (int i = 0; i < (1 << half2); i++)
		{
			for (int j = 0; j < half2; j++)
			{
				if (i & (1 << j))
				{
					right[i] += arr[j + half1];
				}
			}
		}
		sort(right, right + (1 << half2));
		for (int i = 0; i < (1 << half1); i++)
		{
			if (left[i] <= W)
			{
				int index = upper_bound(right, right + (1 << half2), (W - left[i])) - right;
				count += index;
			}
		}
		cout << "Case " << cs++ << ": " << count << endl;
	}
}
