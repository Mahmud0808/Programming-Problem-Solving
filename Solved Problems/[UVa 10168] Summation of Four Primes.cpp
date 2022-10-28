#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long int
#define maxN 10000005

vector < ll > prime;
bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += i)
				isPrime[j] = false;
	prime.push_back(2);
	for (ll i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

void check(ll N)
{
	if (N < 8)
		cout << "Impossible." << endl;
	else
	{
		ll sz = prime.size(), num11, num12, num21, num22, num31, num32;
		bool chk1, chk2, chk3, chk4;
		for (int i = 0; i < sz; i++)
		{
			chk1 = chk2 = chk3 = chk4 = false;
			num11 = prime[i];
			chk1 = true;
			num12 = N - num11;
			for (int j = 0; j < sz; j++)
			{
				num21 = prime[j];
				chk2 = true;
				num22 = num12 - num21;
				for (int k = 0; k < sz; k++)
				{
					num31 = prime[k];
					chk3 = true;
					num32 = num22 - num31;
					if (num31 > num32)
						break;
					if (isPrime[num32])
						chk4 = true;
					if (chk1 && chk2 && chk3 && chk4)
						break;
					if (num11 + num21 + num31 + num32 > N)
						break;
				}
				if (num21 > num22)
					break;
				if (chk1 && chk2 && chk3 && chk4)
					break;
			}
			if (chk1 && chk2 && chk3 && chk4)
				break;
		}
		cout << num11 << ' ' << num21 << ' ' << num31 << ' ' << num32 << endl;
	}
}

int main()
{
	sieve();
	ll N;
	while (cin >> N)
	{
		check(N);
	}
}
