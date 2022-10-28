#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int count = 0, tmp = n, tmp2;
		while (tmp > 1)
		{
			count += tmp / k;
			tmp -= k * (tmp / k) - tmp / k;
			if (tmp < k)
				break;
		}
		cout << (n + count) << endl;
	}
}
