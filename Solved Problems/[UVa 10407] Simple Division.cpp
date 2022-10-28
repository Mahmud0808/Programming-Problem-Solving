#include <iostream>
#include <cmath>
using namespace std;

int n[1005];

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}

int main()
{
	int i = 0, r;
	while (cin >> n[i])
	{
		if (n[0] == 0)
			break;
		else if (n[i] == 0)
		{
			int ans = abs(n[0] - n[1]);
			for (int j = 1; j < i; j++)
			{
				ans = gcd(ans, abs(n[j - 1] - n[j]));
			}
			cout << ans << endl;
			i = 0;
		}
		else
			i++;
	}
}
