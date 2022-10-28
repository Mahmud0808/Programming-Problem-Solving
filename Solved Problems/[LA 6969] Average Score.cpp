#include <iostream>
using namespace std;

int main()
{
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int A[N - 1], B[M], totalA = 0, totalB = 0;
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A[i];
			totalA += A[i];
		}
		for (int i = 0; i < M; i++)
		{
			cin >> B[i];
			totalB += B[i];
		}
		bool first = true, last = false;
		int lower, upper;
		for (int i = 0; i <= 100; i++)
		{
			double avgA = (double)(totalA + i) / N;
			double avgB = (double)totalB / M;
			double newA = (double)totalA / (N - 1);
			double newB = (double)(totalB + i) / (M + 1);
			if (newA > avgA && newB > avgB)
			{
				if (first)
				{
					lower = i;
					upper = i;
					first = false;
					last = true;
				}
				else if (last)
				{
					upper = i;
				}
				if (!first)
				{
					if (newA <= avgA || newB <= avgB)
					{
						break;
					}
				}
			}
		}
		cout << lower << ' ' << upper << endl;
	}
}
