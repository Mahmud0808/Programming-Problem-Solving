#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long int

vector < long long int >divisor;

void divs(long long int n)
{
	int sq = ceil(sqrt(n));
	for (int i = 1; i < sq; i++)
	{
		if (n % i == 0)
		{
			divisor.push_back(i);
			divisor.push_back(n / i);
		}
	}
	if (pow(sq, 2) == n)
	{
		divisor.push_back(sq);
	}
}

long long int gcd(long long int a, long long int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

long long int lcm(long long int a, long long int b)
{
	return ((a * b) / gcd(a, b));
}

int lcmCount(int n)
{
	int sz = divisor.size(), count = 0;
	sort(divisor.begin(), divisor.end());
	for (int i = 0; i < sz; i++)
	{
		for (int j = i; j < sz; j++)
		{
			if (lcm(divisor[i], divisor[j]) == n)
			{
				count++;
			}
		}
	}
	divisor.clear();
	return count;
}

int main()
{
	long long int N;
	while (cin >> N && N)
	{
		divs(N);
		cout << N << ' ' << (lcmCount(N)) << endl;
	}
}
