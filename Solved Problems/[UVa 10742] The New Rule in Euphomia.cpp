#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 1000005

vector < int >prime;
bitset < maxN > isP;

void sieve()
{
	isP.set();
	prime.push_back(2);
	for (int i = 4; i < maxN; i += 2)
		isP[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isP[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isP[j] = false;
	for (int i = 3; i < maxN; i += 2)
		if (isP[i])
			prime.push_back(i);
}

int main()
{
	sieve();
	int n, cs = 1;
	while (cin >> n && n)
	{
		long int abacus = 0;
		for (int i = 0; prime[i] < n - 2; i++)
		{
			int uppr = upper_bound(prime.begin(), prime.end(), (n - prime[i])) - prime.begin();
			if (uppr <= i)
				break;
			abacus += uppr - i - 1;
		}
		cout << "Case " << cs++ << ": " << abacus << endl;
	}
}
