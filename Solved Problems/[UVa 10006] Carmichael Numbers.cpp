#include <iostream>
#include <bitset>
using namespace std;

#define ll long long int
#define maxN 65500

bitset < maxN > isPrime;
int res[maxN];
bool charmichael[maxN];

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

ll _pow(ll a, int n, int m)
{
	ll res = 1;
	a %= m;
	if (!a)
		return a;
	while (n)
	{
		if (n % 2)
			res = (res * a) % m;
		n >>= 1;
		a = (a * a) % m;
	}
	return res;
}

bool fermat(int N)
{
	for (int i = 2; i < N; i++)
	{
		if (_pow(i, N, N) != i)
			return false;
	}
	return true;
}

void preCalc()
{
	sieve();
	for (int i = 4; i < maxN; i++)
	{
		if (!isPrime[i])
		{
			charmichael[i] = fermat(i);
		}
	}
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n)
	{
		if (charmichael[n])
			cout << "The number " << n << " is a Carmichael number." << endl;
		else
			cout << n << " is normal." << endl;
	}
}
