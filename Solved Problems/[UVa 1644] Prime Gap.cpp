#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

#define maxN 1299712

vector <int> prime;
bitset <maxN> isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i=4; i<maxN; i+=2)
		isPrime[i]=false;
	for (int i=3; i*i<maxN; i+=2)
		if (isPrime[i])
			for (int j=i*i; j<maxN; j+=2*i)
				isPrime[j]=false;
	prime.push_back(2);
	for (int i=3; i<maxN; i+=2)
		if (isPrime[i])
			prime.push_back(i);
}

int main()
{
	sieve();
	int n;
	while (cin >> n && n)
	{
		if (isPrime[n])
		{
			cout << 0 << endl;
			continue;
		}
		int idx = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
		if (n < prime[idx])
			idx--;
		cout << prime[idx+1]-prime[idx] << endl;
	}
}
