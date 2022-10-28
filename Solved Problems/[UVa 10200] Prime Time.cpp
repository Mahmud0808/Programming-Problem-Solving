#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

#define maxN 100010050

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

int main()
{
	sieve();
	int a, b;
	while (cin >> a >> b)
	{
		double N, wrong = 0.0;
		for (int i = a; i <= b; i++)
		{
			int tmp = i * i + i + 41;
			if (!isPrime[tmp])
				wrong++;
		}
		double percentage = (100.0 - (wrong / double (b - a + 1.0))*100.0) + 1e-9;
		cout << fixed << setprecision(2) << percentage << endl;
	}
}
