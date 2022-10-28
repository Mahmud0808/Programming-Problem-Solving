#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, cs=1;
	while (cin >> a >> b && a+b)
	{
		if (a==1 || b==1)
		{
			cout << "Case " << cs++ << ": " << 0 << endl;
			continue;
		}
		long double x=1, y=1;
		for (int i=3; i<=a; i++)
		{
			x*=(double)i/(i-2);
		}
		for (int i=3; i<=b; i++)
		{
			y*=(double)i/(i-2);
		}
		long long int P = round(x)*round(y);
		cout << "Case " << cs++ << ": " << P << endl;
	}
}
