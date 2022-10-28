#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define maxN 10000005

vector < int >prime;
bitset < 10000005 > isP;

void sieve()
{
	isP.set();
	isP[0] = isP[1] = false;
	for (int i = 4; i < maxN; i += 2)
		isP[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isP[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isP[j] = false;
	prime.push_back(2);
	for (int i = 3; i < maxN; i += 2)
		if (isP[i])
			prime.push_back(i);
}

int main()
{
	sieve();
	int T, n, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> n;
		int cnt = 0, idx = 0;
		while (prime[idx] <= n - prime[idx])
		{
			if (isP[n - prime[idx]])
				cnt++;
			idx++;
		}
		cout << "Case " << cs++ << ": " << cnt << endl;
	}
}
