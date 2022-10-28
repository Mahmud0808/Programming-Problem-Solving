#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	ll Y, P;
	while (cin >> Y >> P)
	{
		ll arr[P];
		for (ll i = 0; i < P; i++)
			cin >> arr[i];
		ll i, j, max = 0, first, last, count;
		for (i = 0; i < P - 1; i++)
		{
			count = 1;
			for (j = i + 1; j < P; j++)
			{
				if (arr[j] - arr[i] + 1 > Y)
					break;
				else
					count++;
			}
			if (count > max)
			{
				max = count;
				first = arr[i];
				last = arr[j - 1];
			}
		}
		cout << max << ' ' << first << ' ' << last << endl;
	}
}
