#include <iostream>
using namespace std;

#define ll long long int

int main()
{
	ll A, L, a, count, cs = 1;
	while (cin >> A >> L && A >= 1 && L >= 1)
	{
		count = 1, a = A;
		while (A != 1)
		{
			if (A & 1)
			{
				A = 3 * A + 1;
				count++;
			}
			if (A > L)
			{
				count--;
				break;
			}
			if (!(A & 1))
			{
				while (!(A % 2))
				{
					A /= 2;
					count++;
				}
			}
		}
		cout << "Case " << cs++ << ": A = " << a << ", limit = " << L << ", number of terms = " << count << endl;
	}
}
