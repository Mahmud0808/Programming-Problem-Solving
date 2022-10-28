#include <iostream>
#include <cmath>
using namespace std;

const double limit = 0.5;

int main()
{
	int T, n, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> n;
		int people = 1;
		double probability = 1.0;
		while (probability > limit)
		{
			probability *= (1.0 - ((double)people / n));
			people++;
		}
		cout << "Case " << cs++ << ": " << people - 1 << endl;
	}
}
