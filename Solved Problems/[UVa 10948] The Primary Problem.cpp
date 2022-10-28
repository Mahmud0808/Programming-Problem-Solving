#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define maxN 1000005

vector < int >prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	int maxn = maxN / 2;
	prime.push_back(2);
	for (int i = 3; i <= maxn; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

int main()
{
	sieve();
	int N;
	while (cin >> N && N)
	{
		int idx = 0, num2 = N - prime[idx];
		while (!isPrime[num2])
		{
			idx++;
			num2 = N - prime[idx];
			if (num2 < N / 2)
				break;
		}
		if (isPrime[num2])
			cout << N << ':' << endl << prime[idx] << '+' << num2 << endl;
		else
			cout << N << ':' << endl << "NO WAY!" << endl;
	}
}
