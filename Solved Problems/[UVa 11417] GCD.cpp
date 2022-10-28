#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	return GCD(b % a, a);
}

int main()
{
	int N;
	while (cin >> N && N)
	{
		long long int G = 0;

		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				G += GCD(i, j);
			}
		}
		cout << G << endl;
	}
}
