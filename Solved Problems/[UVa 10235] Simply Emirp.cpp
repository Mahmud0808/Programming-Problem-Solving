#include <iostream>
#include <bitset>
using namespace std;

#define maxN 1000005

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
}

bool isEmirp(int N)
{
	int num = 0, tmp = N;
	while (N)
	{
		num = num * 10 + (N % 10);
		N /= 10;
	}
	if (tmp == num)
		return false;
	return isPrime[num];
}

int main()
{
	sieve();
	int N;
	while (cin >> N)
	{
		if (isPrime[N])
		{
			if (isEmirp(N))
				cout << N << " is emirp." << endl;
			else
				cout << N << " is prime." << endl;
		}
		else
			cout << N << " is not prime." << endl;
	}
}
