#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T, tmp, cs = 1;
	unsigned int N1, N2, X, Y;
	cin >> T;
	while (T--)
	{
		scanf("%X %X", &N1, &N2);
		int left = 0, right = 0;
		X = N1, Y = N2;
		while (X != Y && right < 32)
		{
			X = (X << 31) | (X >> 1);
			right++;
		}
		X = N1, Y = N2;
		while (X != Y && left < 32)
		{
			X = (X >> 31) | (X << 1);
			left++;
		}
		if (left == 32)
			cout << "Case #" << cs++ << ": Not possible" << endl;
		else if (left < right)
			cout << "Case #" << cs++ << ": " << left << " Left" << endl;
		else if (right < left)
			cout << "Case #" << cs++ << ": " << right << " Right" << endl;
		else
			cout << "Case #" << cs++ << ": " << right << " Any" << endl;
	}
}
