#include <iostream>
using namespace std;

int main()
{
	long long int n, divisor;
	long double res;
	bool newl=false;
	while (cin >> n)
	{
		if (newl)
			cout << endl;
		else
			newl=true;
		res=1;
		for (int i=2*n; (i-n)>1; i--)
		{
			res *= (double)i/(double)(i-n);
		}
		cout << res << endl;
	}
}

// Catalan Numbers C(n)=(2*n)!/((n+1)!*n!)
