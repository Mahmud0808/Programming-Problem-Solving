#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct num
{
	int numerator, denominator;
	double fraction;
} N;

int gcd(int a, int b)
{
	return !a ? b : gcd(b % a, a);
}

bool cmp(num a, num b)
{
	if (a.fraction < b.fraction)
		return true;
	else
		return false;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector < num > sequence;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (gcd(i, j) == 1)
				{
					N.fraction = (double)j / i;
					N.numerator = j;
					N.denominator = i;
					sequence.push_back(N);
				}
			}
		}
		sort(sequence.begin(), sequence.end(), cmp);
		cout << sequence[k - 1].numerator << '/' << sequence[k - 1].denominator << endl;
		sequence.clear();
	}
}
