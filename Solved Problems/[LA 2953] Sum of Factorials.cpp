#include <iostream>
using namespace std;

int factorial[10];

void preCalc()
{
	factorial[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n >= 0)
	{
		if (!n)
		{
			cout << "NO" << endl;
			continue;
		}
		for (int i = 9; i >= 0; i--)
		{
			if (factorial[i] <= n)
				n -= factorial[i];
		}
		if (!n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
