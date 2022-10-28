#include <iostream>
using namespace std;

int main()
{
	long long int T, G, L;
	cin >> T;
	while (T--)
	{
		cin >> G >> L;
		if (L % G != 0)
			cout << -1 << endl;
		else
			cout << G << ' ' << L << endl;
	}
}
