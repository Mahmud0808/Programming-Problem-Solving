#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

void primeGen(vector < int >&prime)
{
	bool primes[1005];
	memset(primes, true, sizeof(primes));
	for (int i = 2; i <= 1005; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				primes[j] = false;
			}
		}
	}
	for (int i = 1; i <= 1005; i++)
	{
		if (primes[i])
		{
			prime.push_back(i);
		}
	}
}

int main()
{
	vector < int >prime;
	primeGen(prime);
	int N, C, C2, count, start, end;
	while (cin >> N >> C)
	{
		count = 0;
	  for (auto i:prime)
		{
			if (i > N)
				break;
			count++;
		}
		(count % 2 == 0) ? C2 = 2 * C : C2 = (2 * C) - 1;
		if (N <= C2 || count <= C2)
			start = 0;
		else
			start = abs(count - C2) / 2;
		end = 0;
		cout << N << ' ' << C << ':';
		for (int i = start;; i++)
		{
			if (prime[i] > N)
				break;
			cout << ' ' << prime[i];
			end++;
			if (end == C2)
				break;
		}
		cout << endl << endl;
	}
}
