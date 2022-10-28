#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	ll low, high;
	while (cin >> low >> high && (low + high))
	{
		ll ans = (high / 5) - ((low - 1) / 5);
		if (low % 5)
			ans++;
		cout << ans << endl;
	}
}