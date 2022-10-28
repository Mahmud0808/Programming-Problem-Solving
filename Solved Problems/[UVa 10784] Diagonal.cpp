#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

int main()
{
	ll N, res;
	int cs=1;
	while (cin >> N && N)
	{
		ll a = 1.0, b = -3.0, c = -2 * N;
		res = ceil((-b+sqrt(b*b-4*a*c))/(2*a));
		cout << "Case " << cs++ << ": " << res << endl;
	}
}

// Quadratic Equatio from (N*(N-3))/2
