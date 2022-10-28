#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p, q, r, s, t, u;

double solve(double x)
{
	return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0) + u);
}

int main()
{
	double x, low, mid, high;
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		low = 0.0, high = 1.0;
		for (int i = 0; i < 200; i++)
		{
			mid = (low + high) / 2.0;
			if (solve(mid) > 0)
				low = mid;
			else
				high = mid;
		}
		if (solve(0) * solve(1) > 0)
			cout << "No solution" << endl;
		else
			cout << fixed << setprecision(4) << high << endl;
	}
}
