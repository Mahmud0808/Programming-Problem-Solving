#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long int n, k;
	while (cin >> n >> k)
	{
		long double res=0;
		for (int i=k+1; i<=n; i++)
		{
			res+=log10(i)-log10(i-k);
		}
		long long int digit = floor(res+1);
		cout << digit << endl;
	}
}
